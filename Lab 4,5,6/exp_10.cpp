//Q 10
#include<iostream>
using namespace std;

class Vector{
    int size;
    

    public:
    int *arr;
    Vector(int size){
        this->size=size;
        arr = new int[size];
        
    }

    ~Vector(){
        delete [] arr;
        
    }

    friend void operator>>(istream&mycin,Vector&v){
        cout<<"Enter Elements:";
               for(int i=0;i<v.size;i++){
                   mycin>>v.arr[i];
               }
               
    }

    friend void operator<<(ostream&mycout,Vector &v){
        cout<<"Entered Elements:";
        for(int i=0;i<v.size;i++){
            mycout<<v.arr[i]<<" ";
        }
        mycout<<endl;
    }

    friend void operator+(Vector v1,Vector v2){
                Vector v3(v1.size);

        for(int i=0;i<v1.size;i++){
            v3.arr[i]=v1.arr[i]+v2.arr[i];
        }
        cout<<v3;
        return;
    };
    friend void operator-(Vector v1,Vector v2){
        Vector v4(v1.size);

        for(int i=0;i<v1.size;i++){
            v4.arr[i]=v1.arr[i]-v2.arr[i];
        }
        cout<<v4;
        return;
    };

};

int main(){

    Vector v1(5);
    cin>>v1;
    
    Vector v2(5);
    cin>>v2;
    
    v1+v2;
    v1-v2;
    
    
    
    return 0;



}