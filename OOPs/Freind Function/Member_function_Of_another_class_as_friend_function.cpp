#include<iostream>
using namespace std;

class BaseClass;

class AnotherClass{
    public:
    void friendFunction(BaseClass &object);
};
class BaseClass{
    private:
    int private_variable;
    protected:
    int protected_variable;
    void greetings(void){
        cout<<"Jai Shree Ram!"<<endl;
    }
    public:
    BaseClass(){
        private_variable = 10;
        protected_variable = 20;
    }
    friend void AnotherClass::friendFunction(BaseClass &object);
};

void AnotherClass::friendFunction(BaseClass& object){
    object.greetings();
    cout<<"Private_Variable: "<<object.private_variable<<endl;
    cout<<"Protected_Variable: "<<object.protected_variable<<endl;
}
int main(){
    BaseClass B;
    AnotherClass A;
    A.friendFunction(B);
    return 0;
}