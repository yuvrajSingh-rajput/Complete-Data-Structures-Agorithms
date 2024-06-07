#include<bits/stdc++.h>
using namespace std;

//* Catching class types exception

class Error{
    int error_code;
    char* error_desc;
    public:
    Error(int c, char* d){
        error_code = c;
        error_desc = new char[strlen(d)];
        strcpy(error_desc,d);
    }
    void error_display(void){
        cout<<"Error code: "<<this->error_code<<"\nError description: "<<error_desc;
    }
};

int main(){
    try{
        cout<<"Press any key to throw a test exception: ";
        cin.get();
        throw Error(99, "Test Exception");
    }
    catch(Error e){
        cout<<"\nException caught successfully!"<<endl;
        e.error_display();
    }
    return 0;
}