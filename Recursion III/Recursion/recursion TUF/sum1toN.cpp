#include<iostream>
using namespace std;

int Sum1toN(int n){
    if(n==0){
        return 0;
    }
    return Sum1toN(n-1)+n;
}
int main(){
    cout<<Sum1toN(8)<<endl;
    return 0;
}