//Q 1
#include <iostream>
using namespace std;

double calculatePostage(double weight) {
    double postage = 0.0;

    if (weight <= 50) {
        postage = (weight / 10) * 0.50;
    } else if (weight <= 150) {
        postage = (50 / 10) * 0.50 + ((weight - 50) / 10) * 0.40;
    } else if (weight <= 400) {
        postage = (50 / 10) * 0.50 + (100 / 10) * 0.40 + ((weight - 150) / 10) * 0.25;
    } else {
        postage = (50 / 10) * 0.50 + (100 / 10) * 0.40 + (250 / 10) * 0.25 + ((weight - 400) / 1000) * 25.0;
    }

    return postage;
}

int main() {
    double weight;
    cout << "Enter the weight of the letter in grams: ";
    cin >> weight;

    double postage = calculatePostage(weight);
    cout << "The postage to be paid is Rs. " << postage << endl;

    return 0;
}
