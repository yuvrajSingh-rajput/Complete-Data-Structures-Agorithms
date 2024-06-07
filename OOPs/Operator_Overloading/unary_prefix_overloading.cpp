#include<iostream>
using namespace std;

class Prefix{
    private:
    int num;
    public:
    Prefix(){num = 0;}
    Prefix(int n){num = n;}
    void Display(){
        cout<<this->num<<endl;
    }
    void operator++(){
        this->num += 1;
    }
    friend Prefix operator--(Prefix&);
};
Prefix operator--(Prefix& object){
    object.num -= 1;
    return object;
}
int main(){
    
    return 0;
}