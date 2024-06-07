#include<iostream>
using namespace std;

int main(){
    //The first element (arr) of an array is act as a address of that paricular array for e.g.;
    int arr[] = {3,5,6,7,9};
    int *ptr = arr; //or &arr[0]
    
    //(ptr + 1) is equivalent to &arr[1] while *(ptr + 1) is equivalent to arr[1];
    
    cout<<"Printing the addresses of elements--------------->"<<endl;

    for(int i=0;i<5;i++){
        cout<<(ptr +i)<<endl;
    }

    cout<<"Printing values of array----------------------->"<<endl;

    for(int i=0;i<5;i++){
        cout<<*(ptr + i)<<endl;
    }
    return 0;

    //If we don't know the data type of an element and wanna use in pointer then intialize data type of pointer as (void) for e.g.;
    float a = 9.06;
    void *ptr = &a;
}