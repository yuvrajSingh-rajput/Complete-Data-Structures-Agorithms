//* A void pointer is a pointer that has no associated data type with it. A void pointer can hold an address of any type and can be typecasted to any type.

#include<iostream>
using namespace std;

int main(){
    int a = 20;
    char b = 'V';
    void *p;
    p = &a;
    p = &b;

    //Void pointers cannot be dereferenced, as it is not pointer to object type;
    //? USECASE:  malloc() and calloc() return void * type and this allows these functions to be used to allocate memory of any data type (just because of void *).

    // cout<<*p<<endl       ERROR!  (But if we want to compile it we have to do explicit type casting;

    cout<<*(int*)p<<endl;
    cout<<*(char*)p<<endl; 

    //* The C standard doesn’t allow pointer arithmetic with void pointers. However, in GNU C it is allowed by considering the size of the void as 1.
    return 0;
}