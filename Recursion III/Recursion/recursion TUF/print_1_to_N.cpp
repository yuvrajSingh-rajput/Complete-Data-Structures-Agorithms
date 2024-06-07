#include<iostream>
using namespace std;

void print1toNHelper(int s,int n){
    if(s>n){
        return;
    }
    cout<<s<<" ";
    return print1toNHelper(s+1,n);
}

void print1toN(int n){
    int start = 1;
    print1toNHelper(start,n);
}

int main(){
    print1toN(6);
    return 0;
}