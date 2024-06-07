#include<iostream>
using namespace std;

class Complex{
    int real;
    int img;
    public:
    Complex(){real = 0;img = 0;}
    Complex(int r,int i){real = r;img = i;}
    void Display(void){
        cout<<"Result is: ("<<real<<") + ("<<img<<")i"<<endl;
    }
    //Plus Overloading;
    Complex operator+(const Complex &C){
        Complex temp;
        temp.real = this->real + C.real;
        temp.img = this->img + C.img;
        return temp;
    }
    //Minus Overloading
    Complex operator-(const Complex &C){
        Complex temp;
        temp.real = this->real - C.real;
        temp.img = this->img - C.img;
        return temp;
    }
};
int main(){
    Complex c1(2,3);
    Complex c2(3,5);
    cout<<"After Plus(+) Overloading: ";
    Complex c3 = c1 + c2;   //? Same as c3 = c1.Add(c2);
    c3.Display();
    cout<<"After Minus(-) Overloading: ";
    Complex c4 = c1 - c2;
    c4.Display();
    return 0;
}