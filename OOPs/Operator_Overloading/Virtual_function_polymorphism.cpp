#include<iostream>
#include<cmath>
using namespace std;

class shape{
    public:
    virtual double Area() const = 0;    //pure virtual function
};

class circle:public shape{
    private:
    double radius;
    public:
    circle(double r):radius(r){};
    double Area() const override{
        return M_PI * radius * radius;
    }
};
class triangle: public shape{
    private:
    double base;
    double height;
    public:
    triangle(double b,double h):base(b),height(h){};
    double Area() const override{
        return 0.5 * base * height;
    }
};
class rectangle: public shape{
    private:
    double length;
    double breadth;
    public:
    rectangle(double l,double b):length(l),breadth(b){}
    double Area() const override{
        return length * breadth;
    }
};

int main(){
    shape *Shape[3];    //Array of shape pointer.

    circle Circle(5.0);
    rectangle Rectangle(4.0, 2.0);
    triangle Triangle(3.0,5.0);

    //Assigning the address of these shape to the array of pointers;
    Shape[0] = &Circle;
    Shape[1] = &Rectangle;
    Shape[2] = &Triangle;

    //Calculating and displaying the area using polymorphism;
    for(int i=0;i<3;i++){
        cout<<"The calculated area is: "<<Shape[i]->Area()<<endl;
    }
    return 0;
}