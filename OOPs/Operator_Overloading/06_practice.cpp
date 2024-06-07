#include<bits/stdc++.h>
using namespace std;

//* Catch all exceptions;

void test(int x){
    try{
        if(x==1){
            throw x;
        }else if(x == 0){
            throw (char(x));
        }else{
            throw (float(x));
        }
    }
    catch(...){
        cout<<"Exception caught\n";
    }
}

int main(){
    test(0);
    test(1);
    test(-1);
    cout<<"END";
    return 0;
}