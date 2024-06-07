#include<bits/stdc++.h>
using namespace std;

class Complex{
    private:
    int real, img;
    public:
    Complex(){}
    Complex(int real,int img){
        this->real = real;
        this->img = img;
    }
    friend ostream &operator << (ostream &out, const Complex &c);
    friend istream &operator >> (istream &in,Complex &c);
};

ostream &operator << (ostream &out, const Complex &c){
    out<< c.real;
    out<<" + "<<c.img<<"i"<<endl;
    return out;
}

istream &operator >> (istream &in, Complex &c){
    cout<<"Enter the real part: ";
    in>>c.real;
    cout<<"Enter the imaginary part: ";
    in>>c.img;
    return in;
}

int main(){
    // Complex c1;
    // cin>>c1;
    // cout<<"The complex object is :"<<endl;
    // cout<<c1;
    cout<<setw(10)<<10<<setw(10)<<67<<setw(10)<<12<<endl;
    return 0;
}