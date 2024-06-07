#include<iostream>
using namespace std;

void area(int* l,int *b){
    int A = ((*l) * (*b));
    cout<<"The required area is: "<<A;
}
int main(){
    int l = 5, b = 3;
    area(&l,&b);
    return 0;
}