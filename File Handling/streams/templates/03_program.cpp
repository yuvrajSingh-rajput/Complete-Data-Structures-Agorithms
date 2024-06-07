// C++ templates with default parameters

#include<bits/stdc++.h>
using namespace std;

template<class T1 = int, class T2 = float>

class myClass{
    T1 var1;
    T2 var2;
    public:
    myClass(T1 var1, T2 var2){
        this->var1 = var1;
        this->var2 = var2;
    }
    void display(void){
        cout<<this->var1<<" "<<this->var2<<endl;
    }
};

int main(){
    myClass<> obj(2,278.11);
    obj.display();
    return 0;
}