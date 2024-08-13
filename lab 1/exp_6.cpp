#include <iostream>
using namespace std;

struct Complex {
    float real;
    float imag;
};

Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex sub(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex mul(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

Complex div(Complex a, Complex b) {
    Complex result;
    int denom = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / denom;
    result.imag = (a.imag * b.real - a.real * b.imag) / denom;
    return result;
}

int main() {
    Complex a, b, result;

    cout << "Enter real part of the first complex number: ";    
    cin >> a.real ;
    cout<<"Enter imaginary part of the first complex number: ";
    cin>> a.imag;
     cout << "Enter real part of the second complex number: ";    
    cin >> b.real ;
    cout<<"Enter imaginary part of the second complex number: ";
    cin>> b.imag;

    char op;
    cout<<"From (+,-,*,/) which operation you want to do on complex numbers ?";
    cin >> op;

    switch (op) {
        case '+':
            result = add(a, b);
            cout << "Result of addition: " << result.real << " + " << result.imag << "i" << endl;
            break;
        case '-':
            result = sub(a, b);
            cout << "Result of subtraction: " << result.real << " + " << result.imag << "i" << endl;
            break;
        case '*':
            result = mul(a, b);
            cout << "Result of multiplication: " << result.real << " + " << result.imag << "i" << endl;
            break;
        case '/':
            if(b.imag==0&&b.real==0){
                cout<<"Division is not possible"<<endl;
            }
            else{
            result = div(a, b);
            cout << "Result of division: " << result.real << " + " << result.imag << "i" << endl;
            }
            break;
        default:
            cout << "Invalid operation" << endl;
            break;
    }

    return 0;
}

