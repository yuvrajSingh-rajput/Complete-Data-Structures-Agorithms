#include<iostream>
#include<sstream>
using namespace std;

int main(){
    // this is used to convert a string part to integer and vice versa;
    string name = "5478333";
    stringstream sso;
    sso<< name;
    int num;
    sso>>num;
    cout<<"The string part = "<<name<<endl;
    cout<<"The integer part = "<<num+3<<endl;
    string s = "23 98 12 33";
    stringstream ss(s);
    double sum = 0,val;
    while(ss>>val){
        sum = sum + val;
    }
    cout<<sum<<endl;
    return 0;
}