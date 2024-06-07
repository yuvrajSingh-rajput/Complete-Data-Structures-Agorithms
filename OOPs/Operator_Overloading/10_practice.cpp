#include<bits/stdc++.h>
using namespace std;

//* Exception handling in constructors.

class A{
    public:
    A(){
        try{
            int t;
            throw t;
        }
        catch(int e){
            // delete e;
            throw e;
        }
    }
};

int main(){
    
    return 0;
}