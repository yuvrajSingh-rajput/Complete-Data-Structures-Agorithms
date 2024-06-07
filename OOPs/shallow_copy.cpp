//! All simple copy constructors are named as shallow copy, it means that one or more objects points to the same memory address.
#include<iostream>
using namespace std;
class Data{
    public:
    char *name;
    int age;
    Data(){
        cout<<"Default constructor is called!"<<endl;
        name  = new char[100];
    }
    
};
int main(){
    
    return 0;
} 