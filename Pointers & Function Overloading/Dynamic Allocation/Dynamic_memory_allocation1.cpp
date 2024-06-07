#include<iostream>
using namespace std;

int main(){
    int *n = new int;
    *n = 10;
    cout<<*n<<endl;
    double *d = new double;
    char *c = new char;
    //Dynamic array;
    int num;
    cout<<"Enter the number of element of the array: ";
    int *arr = new int[num];
    /* 
    let us suppose num = 50;
    stack memory : 8 Bytes;
    Heap memory : 200 Bytes;
    */
   
    return 0;
}