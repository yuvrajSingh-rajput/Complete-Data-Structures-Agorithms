#include<iostream>
using namespace std;
//* Preprocessors do their work before compilation.
#define pi 3.14
#define Multiply(a,b) a*b
#define Square(x) x*x

int main(){
    int radius = 3.4;
    cout<<"Area = "<<pi * radius * radius<<endl;
    cout<<Multiply(2+3,4+4)<<endl;
    cout<<36/Square(6)<<endl;
    return 0;
}