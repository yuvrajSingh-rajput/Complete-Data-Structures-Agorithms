#include<iostream>
using namespace std;
//! We cannot return a pointer or reference of a local variable of a function;
int& returnByReference(int& x) {
    x += 5;
    return x;
}

int main() {
    int num = 10;
    int& result = returnByReference(num);

    std::cout << "Original num: " << num << std::endl;
    std::cout << "Result reference: " << result << std::endl;

    result = 20; // Modifying through the reference
    std::cout << "Modified num: " << num << std::endl;

    return 0;
}
