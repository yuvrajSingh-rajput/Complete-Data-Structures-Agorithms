#include<iostream>
using namespace std;

void print1toN(int n){
    if(n<1){
        return;
    }
    print1toN(n-1);
    cout<<n<<endl;
}

void printNto1(int n){
    if(n<1){
        return;
    }
    cout<<n<<endl;
    printNto1(n-1);
}

int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}

int main(){
    printNto1(7);
    cout<<factorial(7)<<endl;
    print1toN(7);
    return 0;
}