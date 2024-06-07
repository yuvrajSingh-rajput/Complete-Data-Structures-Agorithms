#include <iostream>
#include <vector>
using namespace std;

void PrintValue(int a)
{
    cout << "Value is: " << a << endl;
}

void forEach(const vector<int> &arr, void (*function)(int))
{
    for (int value : arr)
    {
        function(value);
    }
}
int main()
{
    vector<int> values = {1, 2, 3, 4, 5};
    forEach(values, PrintValue);

    //* Suppose if we do not have the actual Printvalue() function< Then there is a method to pass the function argument as follows:
    //! This is known as lambda function.
    forEach(values, [](int value)
            { 
                cout << "Value is : " << value << endl; });
    return 0;
}