#include<bits/stdc++.h>
using namespace std;

class Complex{
    private:
    /// **********************************
    public:
    int real,img;
    //----------------
    Complex():real(0),img(0){}
    Complex(int r, int i):real(r),img(i){};
    friend void Display(Complex &);
};

Complex operator+(Complex &c1, Complex &c2){
    Complex c;
    c.real = c1.real + c2.real;
    c.img = c1.img + c2.img;
    return c;
}

//* Reference is mandatory---------------------------------------
std::ostream& operator<<(std::ostream &out, Complex &c){
    out<<c.real<<" "<<c.img<<endl;
    return out;
}

int main(){
    Complex c1(2,4), c2(3,5), c3;
    c3 = c1 + c2;
    cout<<c3;
    return 0;
}