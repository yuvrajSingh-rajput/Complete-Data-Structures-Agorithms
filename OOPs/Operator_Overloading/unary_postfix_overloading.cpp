#include<iostream>
using namespace std;

class Postfix{
    int num;
    public:
    Postfix(){num = 0;}
    Postfix(int n){num = n;}
    void Display(){
        cout<<this->num<<endl;
    }
    Postfix operator++(int){
        Postfix temp = *this;
        ++num;
        return temp;
    }
    friend Postfix operator--(Postfix&,int);
};
Postfix operator--(Postfix& obj,int){
    Postfix temp = obj.num;
    obj.num = obj.num-1;
    return temp;
}
int main(){
    Postfix p(5);
    Postfix p1 = p++;
    p.Display();
    Postfix p2 = p--;
    p.Display();
    p2 = p--;
    p.Display();
    return 0;
}