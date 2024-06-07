#include<iostream>
using namespace std;

class Base{
    private:
    int private_member;
    protected:
    int protected_member;
    public:
    Base(){
        private_member = 10;
        protected_member = 20;
    }
    void Hello(){
        cout<<"Hello world!"<<endl;
    }
    friend void friendFunction(Base &object);
};

void friendFunction(Base &object){
    object.Hello();
    cout<<"private_variable: "<<object.private_member<<endl;
    cout<<"protected_variable: "<<object.protected_member<<endl;
}

int main(){
    Base b;
    friendFunction(b);
    return 0;
}