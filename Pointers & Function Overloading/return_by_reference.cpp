#include <iostream>
using namespace std;

int &function(int &a)
{             //* First it takes the reference of the var as an input;
    a = 20;   // changing the actual value of the variable.
    return a; //* Returning the reference of that particular variable;
}
int main()
{
    int n = 10;
    cout << function(n) << endl;

    //! This above function will return the actual reference of the variable rather than the value.

    //* It means that my function itself will act like, as it is the n variable, because it has the reference of that variable.
    //? LETS MODIFY IT--->

    function(n) = 25;

    cout<<n<<endl;
    cout<<function(n)<<endl;
    cout<<n<<endl;

    return 0;
}