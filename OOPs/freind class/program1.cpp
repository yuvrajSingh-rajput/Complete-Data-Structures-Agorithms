#include<iostream>
using namespace std;
//* Friend class can access both function and members of another class, while freind function doesn't.
class GFG{
    private:
    int private_variable;
    protected:
    int protected_variable;
    public:
    //* Constructor
    GFG(){
        private_variable = 10;
        protected_variable = 20;
    }
    //*Member function
    void Greetings(void){
        cout<<"Jay Shree Ram!"<<endl;
    }
    //Friend class declaration.
    friend class F;
};
//* Class F is the friend of class GFG, so that it is able to access the private and protected members.
class F{
    public:
    void Display(GFG &t){
        t.Greetings();
        cout<<"private_variable: "<<t.private_variable<<endl;
        cout<<"protected_variable: "<<t.private_variable<<endl;
    }
};
int main(){
    GFG g;
    F fr;
    fr.Display(g);
    return 0;
}