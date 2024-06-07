#include<iostream>
using namespace std;
class Complex {
    private:
    int real;int img;
    public:
    //Default Constructor;
    Complex():real(0),img(0){}
    //Parameterized Constructor;
    Complex(int r,int i):real(r),img(i){};
    void displayResult(){
        cout<<"Result is : ("<<this->real<<") + ("<<this->img<<")i"<<endl;
    }
    Complex operator*(const Complex &C);
};
Complex Complex::operator*(const Complex &C){
    Complex temp;
    temp.real = (this->real * C.real) - (this->img * C.img);
    temp.img = (this->real * C.img) + (this->img * C.real);
    return temp;
}
int main(){
    Complex c1(2,3),c2(5,1);
    Complex c3 = c1*c2;
    c3.displayResult();
    return 0;
}