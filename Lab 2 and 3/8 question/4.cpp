//Q 4
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PatientDatabase;

class Patient {
private:
    string name;
    string sex;
    int age;
    int wardNumber;
    int bedNumber;
    string illness;
    string admissionDate;
    static int patientCount;

public:

    Patient()
        : name("Unknown"), sex("Unknown"), age(0), wardNumber(0), bedNumber(0),
          illness("Unknown"), admissionDate("Unknown") {
        patientCount++;
    }

    Patient(string name, string sex, int age, int wardNumber, int bedNumber,
            string illness, string admissionDate)
        : name(name), sex(sex), age(age), wardNumber(wardNumber),
          bedNumber(bedNumber), illness(illness), admissionDate(admissionDate) {
        patientCount++;
    }

    Patient(const Patient &other)
        : name(other.name), sex(other.sex), age(other.age), wardNumber(other.wardNumber),
          bedNumber(other.bedNumber), illness(other.illness), admissionDate(other.admissionDate) {
        patientCount++;
    }

    ~Patient() {
        patientCount--;
        cout << "Destructor called for patient: " << name << endl;
    }

    inline void display() const {
        cout << "Name: " << name << endl;
        cout << "Sex: " << sex << endl;
        cout << "Age: " << age << endl;
        cout << "Ward Number: " << wardNumber << endl;
        cout << "Bed Number: " << bedNumber << endl;
        cout << "Illness: " << illness << endl;
        cout << "Date of Admission: " << admissionDate << endl;
    }

    static void displayPatientCount() {
        cout << "Total patients: " << patientCount << endl;
    }

    friend class PatientDatabase;

    static Patient *createPatient() {
        return new Patient();
    }

    static void deletePatient(Patient *patient) {
        delete patient;
    }
};


int Patient::patientCount = 0;

class PatientDatabase {
private:
    vector<Patient *> patients;

public:
    void addPatient(Patient *patient) {
        patients.push_back(patient);
    }

    void displayAllPatients() {
        if (patients.empty()) {
            cout << "No patients in the database." << endl;
            return;
        }
        for (size_t i = 0; i < patients.size(); ++i) {
            cout << "\nPatient " << i + 1 << ":\n";
            patients[i]->display();
        }
    }

    ~PatientDatabase() {
        for (auto &patient : patients) {
            Patient::deletePatient(patient);
        }
        patients.clear();
        cout << "Patient database cleaned up." << endl;
    }
};

int main() {
    PatientDatabase db;

    int choice;
    do {
        cout << "\n--- Patient Management System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Display All Patients\n";
        cout << "3. Display Total Patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1: {
            string name, sex, illness, admissionDate;
            int age, wardNumber, bedNumber;

            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter sex (Male/Female): ";
            getline(cin, sex);
            cout << "Enter age: ";
            cin >> age;
            cin.ignore();
            cout << "Enter ward number: ";
            cin >> wardNumber;
            cin.ignore();
            cout << "Enter bed number: ";
            cin >> bedNumber;
            cin.ignore();
            cout << "Enter illness: ";
            getline(cin, illness);
            cout << "Enter date of admission (dd-mm-yyyy): ";
            getline(cin, admissionDate);

            Patient *newPatient = Patient::createPatient();
            *newPatient = Patient(name, sex, age, wardNumber, bedNumber, illness, admissionDate);
            db.addPatient(newPatient);

            break;
        }
        case 2:
            db.displayAllPatients();
            break;
        case 3:
            Patient::displayPatientCount();
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
