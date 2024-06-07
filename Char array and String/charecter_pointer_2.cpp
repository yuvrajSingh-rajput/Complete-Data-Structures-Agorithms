#include<iostream>
#include<cstring>
using namespace std;

const char* createDynamicString(){
    char *str = new char[20];
    strcpy(str,"Dynamic String");
    return str;
}
int main(){
    const char * dynChar = createDynamicString();
    cout<<dynChar<<endl;
    delete[] dynChar;
    return 0;
}