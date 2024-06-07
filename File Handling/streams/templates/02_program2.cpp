//templates of multiple parameters.

#include<bits/stdc++.h>
using namespace std;

template<class T1, class T2>

class myClass{
    T1 data1;
    T2 data2;
    public:

    // constructor
    myClass(T1 a, T2 b){
        this->data1 = a;
        this->data2 = b;
    }

    void display(void){
        cout<< this->data1<<" "<<this->data2<<endl;
    }
};

int main(){
    myClass <int, char> obj(1,'3');
    obj.display();
    return 0;
}