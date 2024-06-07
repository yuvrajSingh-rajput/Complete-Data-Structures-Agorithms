#include<iostream>
using namespace std;
void Multiple(int *,int *,int *,int *);
int main(){
    int l,b,h,r;
    cout<<"Enter the value of length: ";
    cin>>l;
    cout<<"Enter the value of width: ";
    cin>>b;
    cout<<"Enter the value of height: ";
    cin>>h;
    cout<<"Enter the value of radius: ";
    cin>>r;
//With the pass by reference method we can use single fuction for a multiple use;
    Multiple(&l,&b,&h,&r);
    return 0;
}
void Multiple(int* l,int* b,int* h,int* r){
    int area = ((*l)*(*b));
    cout<<"The area of base is: "<<area<<endl;
    int volcu = ((*l)*(*b)*(*h));
    cout<<"The volume of cuboid is: "<<volcu<<endl;
    float volcy = (3.14*(*r)*(*r)*(*h));
    cout<<"The volume made by cylinder is: "<<volcy<<endl;
}