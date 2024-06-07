#include<iostream>
using namespace std;

int* returnByPointer(int* x) {
    (*x) += 5;
    return x;
}

int main() {
    int num = 10;
    int* result = returnByPointer(&num);

    std::cout << "Original num: " << num << std::endl;
    std::cout << "Result pointer: " << *result << std::endl;

    (*result) = 20; // Modifying through the pointer
    std::cout << "Modified num: " << num << std::endl;

    return 0;
}
