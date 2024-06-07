#include<bits/stdc++.h>
using namespace std;

void test(int x){
    try{
        if(x == 1){
            throw (x);
        }else if(x == 0){
            throw ('x');
        }else if(x == -1){
            throw ((double)x);
        }else{
            cout<<"No Exceptions are caught and END of try block."<<endl;
        }
    }
    catch(char c){
        cout<<"Caught a charecter\n";
    }
    catch(int m){
        cout<<"Caught a integer\n";
    }
    catch(double d){
        cout<<"Caught a double\n";
    }
    cout<<"END of try-catch system"<<endl;
}

int main(){
    cout<<"Testing multiple catches"<<endl;
    cout<<"x == 1"<<endl;
    test(1);
    cout<<"x == 0"<<endl;
    test(0);
    cout<<"x == -1"<<endl;
    test(-1);
    return 0;
}