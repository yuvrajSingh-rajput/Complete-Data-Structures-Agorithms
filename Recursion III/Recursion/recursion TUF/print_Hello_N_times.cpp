#include<iostream>
using namespace std;

void printNtimesHelper(int s,int n){
    if(s>n){
        return;
    }
    cout<<"Hello World!"<<endl;
    return printNtimesHelper(s+1,n);
}

void printNtimes(int n){
    int start = 1;
    printNtimesHelper(start,n);
}

int main(){
    printNtimes(6);
    return 0;
}