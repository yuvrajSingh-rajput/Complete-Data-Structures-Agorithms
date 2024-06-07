#include<bits/stdc++.h>
using namespace std;

void divide(double x , double y){
    cout<<"\ninside the function\n";
    try{
        if(y == 0.0){
            throw y;
        }else{
            cout<<"Division = "<<x/y<<endl;
        }
    }
    catch(double i){
        cout<<"Exception caught double inside the function!"<<endl;
        throw;
    }
}

int main(){
    cout<< "Inside main\n";
    try{
        divide(1.0, 6.0);
        divide(1.0, 0.0);
    }
    catch(double){
        cout<<"Exception caught double inside the main!\n";
    }
    cout<<"END of MAIN\n";
    return 0;
}