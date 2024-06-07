#include<iostream>
using namespace std;

int main(){
    char name[12];
    cin>>name;
    cout<<name<<endl;

    int count =0;
    for(char c:name){
        count++;
    }
    cout<<"length of entire name character array is: "<<count<<endl;
    count = 0;
    for(int i=0;name[i] !='\0';i++){
        count ++;
    }
    // space ,\t,\n act as a NULL charecter, hence cin will stop reading input from there where you strated using it;

    cout<<"Lenght of the string is: "<<count<<endl;
    return 0;
}