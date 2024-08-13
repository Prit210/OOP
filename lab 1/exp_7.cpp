#include<iostream>
using namespace std;
 struct arithmetic{
    float no1,no2;
};
void add(arithmetic a){
    cout<<a.no1<<"+"<<a.no2<<"="<<(a.no1+a.no2)<<endl;
}
void sub(arithmetic a){
    cout<<a.no1<<"-"<<a.no2<<"="<<(a.no1-a.no2)<<endl;
}

void mul(arithmetic a){
    cout<<a.no1<<"*"<<a.no2<<"="<<(a.no1*a.no2)<<endl;
}

void division(arithmetic a){
    if(a.no2==0){
        cout<<"Division is not possible."<<endl;
    }
    else{
        cout<<a.no1<<"/"<<a.no2<<"="<<(a.no1/a.no2)<<endl;
    }
}
int main(){
    arithmetic a;
    cout<<"Enter first number: ";
    cin>>a.no1;
    cout<<"Enter second number: ";
    cin>>a.no2;

    char op;
    cout<<"From (+,-,*,/) which operation you want to do on numbers ?";
    cin>>op;

    switch(op){
        case '+':
            add(a);
            break;
        case '-':
            sub(a);
            break;
        case '*':
            mul(a);
            break;
        case '/':
            division(a);
            break;
        default:
            cout<<"Invalid operation";    
    }
}