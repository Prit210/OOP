//Q12
#include <iostream>
using namespace std;

class Matrix {
    int rows, cols;
    double** matrix;

public:
    // Constructor to dynamically allocate memory
    Matrix(int r, int c) : rows(r), cols(c) {
        matrix = new double*[rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = new double[cols];
    }

    // Function to input matrix values
    void inputMatrix() {
        cout << "Enter elements for the " << rows << "x" << cols << " matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    // Function to display matrix
    void displayMatrix() const {
        cout << "Matrix is:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to add matrices
    Matrix add(const Matrix& m2) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] + m2.matrix[i][j];
            }
        }
        return result;
    }

    // Destructor to free dynamically allocated memory
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};

int main() {
    int r, c;
    cout << "Enter number of rows and columns for matrices: ";
    cin >> r >> c;

    Matrix m1(r, c), m2(r, c);
    m1.inputMatrix();
    m2.inputMatrix();

    cout << "Matrix 1:" << endl;
    m1.displayMatrix();

    cout << "Matrix 2:" << endl;
    m2.displayMatrix();

    Matrix result = m1.add(m2);
    cout << "Result of Matrix Addition:" << endl;
    result.displayMatrix();

    return 0;
}
