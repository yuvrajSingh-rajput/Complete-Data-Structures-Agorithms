#include<iostream>
using namespace std;

bool isPower(int n){
    if(n==1){
        return true;
    }
    if(n<=0 || (n%4)!=0){
        return false;
    }
    return isPower(n/4);
}

int main(){
    cout<<isPower(68)<<endl;
    return 0;
}