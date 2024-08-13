#include<iostream>
using namespace std;
 struct arithmetic{
    float no1,no2;
}c;
void add(int no1,int no2){
    cout<<no1<<"+"<<no2<<"="<<(no1+no2)<<endl;
}
void sub(int no1,int no2){
    cout<<no1<<"-"<<no2<<"="<<(no1-no2)<<endl;
}
void mul(int no1,int no2){
    cout<<no1<<"*"<<no2<<"="<<(no1*no2)<<endl;
}
void division(int no1,int no2){
    if(no2==0){
        cout<<"Division is not possible."<<endl;
    }
    else{
        cout<<no1<<"/"<<no2<<"="<<(no1/no2)<<endl;
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
            add(a.no1,a.no2);
            break;
        case '-':
            sub(a.no1,a.no2);
            break;
        case '*':
            mul(a.no1,a.no2);
            break;
        case '/':
            division(a.no1,a.no2);
            break;
        default:
            cout<<"Invalid operation";    
    }
}