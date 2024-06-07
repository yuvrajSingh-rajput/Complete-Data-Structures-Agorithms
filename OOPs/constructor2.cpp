#include<iostream>
using namespace std;

class Complex{
    private:
    int real;
    int imaginary;
    public:
    Complex(){cout<<"Default Constructor called."<<endl;}
    Complex(int re,int img):real(re),imaginary(img){cout<<"Parameterized constructor is called!"<<endl;}
    void Add(Complex &c3);
    void Multiply(Complex &c3);
    void PrintResult(void);
};
void Complex::Add(Complex &c3){
    int Addreal = this->real + c3.real;
    int Addimg = this->imaginary + c3.imaginary;
    this->real = Addreal;
    this->imaginary = Addimg;
}
void Complex::Multiply(Complex &c3){
    int realpart = (this->real * c3.real) - (this->imaginary * c3.imaginary);
    int imgpart = (this->real * c3.imaginary) + (this->imaginary * c3.real);
    this->real = realpart;
    this->imaginary = imgpart;
}
void Complex::PrintResult(void){
    cout<<"Result: ("<<this->real<<") + i("<<this->imaginary<<")"<<endl;
}
int main(){
    Complex *c1 = new Complex(2,4);
    Complex *c2 = new Complex(1,9);
    int query;
    cout<<"Enter 1 for Addition or 2 for multiplication: ";
    cin>>query;
    switch(query){
        case 1:{
            c2->Add(*c1);
            c2->PrintResult();
        }
        break;
        case 2:{
            c2->Multiply(*c1); 
            c2->PrintResult(); 
        }
        break;
        default:
        cout<<"No operation matched!"<<endl;
    }
    return 0;
}