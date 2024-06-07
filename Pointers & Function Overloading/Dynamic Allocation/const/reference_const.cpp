#include<iostream>
using namespace std;

int main(){
    //* case 1:
    const int i = 23;
    // int &a = i;    we can not do this.

    //* case 2:
    int j = 23;
    const int &a = j;
    j++;
    // ! a++ not accepted.

    //* case 3:
    const int k = 23;
    const int & l = k;

    return 0;
}