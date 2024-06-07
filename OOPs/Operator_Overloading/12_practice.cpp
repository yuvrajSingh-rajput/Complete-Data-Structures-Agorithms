#include<bits/stdc++.h>
using namespace std;

//* friend class implementation

class Friendclass{
    public:
    void display(parent &p){
        cout<<"Displaying the data of the parent class."<<endl;
        cout<<"data = "<<p.data<<endl;
    }
};

class parent{
    private:
    int data;
    friend class Friendclass;
    public:
    parent(int data){
        this->data = data;
    }
};

int main(){
    parent p(10);
    Friendclass f;
    f.display(p);
    return 0;
}