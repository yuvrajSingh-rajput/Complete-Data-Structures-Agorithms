#include<iostream>
using namespace std;

class geeks{
    private:
    int length;
    int breadth;

    public:
    geeks(){
        cout<<"Default constructor called."<<endl;
    }
    void setValue(int l,int b){
        this->length = l;
        this->breadth = b;
    }
    int getArea(){
        return (this->length * this->breadth);
    }
};
int main(){
    //Dynamically creation of object.
    geeks *object = new geeks();
    object->setValue(4,3);
    cout<<"The area of the rectangle is: "<<object->getArea()<<endl;
    return 0;
}