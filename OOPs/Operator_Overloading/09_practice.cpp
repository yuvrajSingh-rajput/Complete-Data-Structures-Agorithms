#include<bits/stdc++.h>
using namespace std;

//* specifying the exception.

void test(int x) throw(int, double){
    if(x == 0){
        throw (char(x));
    }else if(x == -1){
        throw ((int)x);
    }else if(x == 1){
        throw ((double)x);
    }
}
int main(){
    try{
        test(0);
        test(-1);
        test(1);
    }
    catch(int x){
        cout<<"Integer exception caught successfully!"<<endl;
    }
    catch(char ch){
        cout<<"Charecter exception caught successfully!"<<endl;
    }
    catch(double d){
        cout<<"Double exception caught successfully!"<<endl;
    }
    return 0;
}