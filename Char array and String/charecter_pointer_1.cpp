#include<iostream>
using namespace std;

//? ------- Normal declared function of return type charecter pointer -----------------//

const char* greet(){
    return ("Hello World!");
}

int main(){
    const char* name = greet();
    cout<<greet()<<endl;
    cout<<name<<endl;
    return 0;
}