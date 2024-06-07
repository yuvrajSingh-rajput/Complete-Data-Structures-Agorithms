#include<bits/stdc++.h>
using namespace std;

void divide(int x, int y, int z){
    cout<<"\nWe are inside the  function\n";
    if((x-y) != 0){
        int R = z/(x-y);
        cout<<"Result = "<<R<<endl;
    }else{
        throw (x-y);
    }
}

int main(){

    try{
        cout<<"We are inside the try block."<<endl;
        divide(10,20,10);   //* invoke divide()
        divide(10,10,20);   //* invoke divide()
    }
    catch(int i){
        cout<<"Caught the Exception "<<i<<endl;
    }

    return 0;
}