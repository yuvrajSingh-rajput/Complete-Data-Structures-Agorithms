#include <iostream>
using namespace std;

//? The use of pointer for the array is can be: We can pass a part of an array except passing whole array.

void value(int *p)  // we are taking a pointer as an input.
{
    cout << p << endl;
}

void update_address(int *p){
    //! We can not change the address of a variable inside the variable.
    p = p + 1;  //(trying to update the address of the variable in main function).
}

void value_update(int *p){
    *p = *p + 1;
}
int main()
{
    int a = 5;  //* Declaration of variable a.

    int *ptr = &a;  //! ptr = &a (address of a)--> it is pointing towards address of a.

    value(ptr);  //* we are passing the  address the function, There can be another method of pointing this for eg: value(&a)

    cout<<"Before updating the address of variable: "<<ptr<<endl;

    update_address(ptr);

    cout<<"Before updating the address of variable: "<<ptr<<endl;

//! The main reason of not changing the address of the variable because address is acting like pass by value here.

    cout<<"Before updating the value of varible: "<<(*ptr)<<endl;

    value_update(ptr);

    cout<<"after updating the value of varible: "<<(*ptr)<<endl;

    cout<<"size of sizeof(*ptr): "<<sizeof(*ptr)<<endl;

    cout<<"size of sizeof(ptr): "<<sizeof(ptr)<<endl;

    cout<<"size of sizeof(&ptr): "<<sizeof(&ptr)<<endl;
    return 0;
}