#include<iostream>
using namespace std;

inline int max(int a,int b){
    return (a>b)? a:b;
}
int main(){
    cout<<max(2,3)<<endl;
    return 0;
}