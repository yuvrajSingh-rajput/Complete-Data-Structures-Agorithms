#include<iostream>
using namespace std;

double myPow(int x,int n){
    long long nn = n;
    double ans = 1.0;
    if(nn<0){
        nn = -1*nn;
    }
    while(nn!=0){
        if(nn%2==0){
            x = x*x;
            nn = nn/2;
        }
        else{
            ans = x * ans;
            nn = nn - 1;
        }
    }
    if(n<0){
        return double(1.0)/double(ans);
    }
    return ans;
}
int main(){
    cout<<myPow(2,-2)<<endl;
    return 0;
}