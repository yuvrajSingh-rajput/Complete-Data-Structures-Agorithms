#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cout<<"Enter the value of a & b: ";
    cin>>a>>b;
    int x = a-b;
    try{
        if(x != 0){
            cout<<"Result(a/x) = "<<a/x<<endl;
        }else{
            throw(x);   //throws int objects.
            cout<<"Divisor is 0."<<endl;
        }
    }
    catch(int i){
        cout<<"Exception caught: Divide by "<<i<<" can't happen."<<endl;
    }
    cout<<"END";
    return 0;
}