#include<iostream>
using namespace std;

int factorial_Parameterized(int n,int fact=1){
    if(n==0){
        return fact;
    }
    return factorial_Parameterized(n-1,fact*n);
}
int factorial(int n){
    factorial_Parameterized(n);
}

int main(){
    cout<<factorial(7)<<endl;
    return 0;
}