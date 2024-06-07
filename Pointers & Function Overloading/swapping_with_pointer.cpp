#include<iostream>
using namespace std;
int swapping1(int *,int *);

int main(){
    int a,b;
    cout<<"Enter the value of a and b respectively: ";\
    cin>>a>>b;
    swapping1(&a,&b);
    cout<<"After swapping1 a = "<<a<<" & b = "<<b<<endl;
    return 0;
}
int swapping1(int* r,int* s){
    int temp = *r;
    *r = *s;
    *s = temp;
}
