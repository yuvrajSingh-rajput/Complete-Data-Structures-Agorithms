#include<iostream>
using namespace std;

int main(){
    int a = 5;
    //Initializing the pointer.
    int *p;
    //Pointers is used to store the address of an entity. (*)is known as dereference operator.
    p = &a;
    cout<<"The address of a is: "<<p<<endl;
    cout<<"The value of a is: "<<*p<<endl;
    return 0;
}