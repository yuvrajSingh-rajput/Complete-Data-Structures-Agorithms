#include<bits/stdc++.h>
using namespace std;

template<class T1, class T2>

double Average(T1 a, T2 b){
    double ans = double(a + b)/2;
    return ans;
}

int main(){
    double a = Average(2,7.5);
    cout<<a<<endl;
    return 0;
}