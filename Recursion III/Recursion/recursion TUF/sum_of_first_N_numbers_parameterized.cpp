#include<iostream>
using namespace std;

int sum1toN_parameterized(int n,int sum=0){
    if(n<1){
        return sum;
    }
    return sum1toN_parameterized(n-1,sum+n);
}
int sum1toN(int n){
    sum1toN_parameterized(n);
}

int main(){
    cout<<sum1toN(3)<<endl;
    return 0;
}