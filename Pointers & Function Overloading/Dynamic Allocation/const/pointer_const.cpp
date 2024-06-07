#include<iostream>
using namespace std;

int main(){
    //TODO: pointer to constant.

    const int i = 23;   //* forward declaration.
    int const *p = &i;  //* pointer points to constant integer.
    p++;   
    int const j = 34;
    p = &j;     

    (*p++); //! not allowed;

    //TODO: constant pointer.

    int k = 23;
    int *const p = &k;
    int l = 34;
    (*p++);
    p = &l;     //!not allowed

    int const *const p2 = &k;
    
    return 0;
}