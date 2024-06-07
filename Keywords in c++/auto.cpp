//? In C++, the auto keyword is used for type inference, allowing the compiler to automatically determine the data type of a variable based on its initialization. This feature was introduced in C++11 to simplify code and make it more readable by reducing the need to explicitly specify variable types.

#include <iostream>
#include <vector>
#include<map>
using namespace std;

//* (2) Auto Type Inference for Function Return Types:
auto sum(int a, int b) -> int
{
    return a + b;
}

int main()
{
    //* (1) Auto Type Inference for Variables:
    auto x = 42;
    auto name = "yuvraj";
    auto pi = 3.14;

    //* (3) Auto Type Inference for Iterators:
    vector<int> numbers = {1, 2, 3, 4, 5};
    for (auto i = numbers.begin(); i != numbers.end(); i++)
    {
        cout << (*i) << " ";
    }

    //* (4) Auto Type Inference in Range-Based For Loops:
    vector<int> nums = {1, 2, 3, 4, 5};
    for (auto i : nums)
    {
        cout << i << " ";
    }

    //* (5) Auto Type Inference for Complex Types:
    std::map<std::string, int> scoreMap;
    // 'auto' is used for the map iterator type
    for (auto it = scoreMap.begin(); it != scoreMap.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}