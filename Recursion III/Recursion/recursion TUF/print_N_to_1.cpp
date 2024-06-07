#include<iostream>
using namespace std;

void print1toNHelper(int s,int n){
    if(s==0){
        return;
    }
    cout<<s<<" ";
    return print1toNHelper(s-1,n);
}

void print1toN(int n){
    int end = n;
    print1toNHelper(end,n);
}

int main(){
    print1toN(6);
    return 0;
}