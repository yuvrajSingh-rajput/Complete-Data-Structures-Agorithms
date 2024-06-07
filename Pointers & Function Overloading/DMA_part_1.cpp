#include <iostream>
using namespace std;
//* 1. Creation of reference variable.--> There will be another variable which will points to same memory address, just their name will be different;

//! passing reference variable to a function.
//? Actually we all want to know why we use reference variable, because we can access the values by that variale itself. then the main use of it in the function.
//______________________________________________________________________________________________________________________________________

void update1(int n)
{
    n++;
}

void update2(int &n)
{ // TODO: Here n is direct targeting the address of i that's why i changes inside main();
    n++;
}

//! We can return by reference;
int &function(int a)
{
    int num = a;
    int &k = num;
    k++;
    return k;
}

//! We can return by pointer also;
int *func(int n)
{
    int *ptr = &n;
    return ptr;
}

int main()
{
    int i = 5;
    // creating a reference variable.
    int &j = i;

    cout << "Before increment from pass by value: " << i << endl;
    update1(i);
    cout << "After increment from pass by value: " << i << endl;

    cout << "Before increment from pass by value: " << i << endl;
    update2(i);
    cout << "After increment from pass by value: " << i << endl;

    cout << "Before increment from pass by value: " << i << endl;
    function(i);
    cout << "After increment from pass by value: " << i << endl;
    return 0;
}