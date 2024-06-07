#include <iostream>
#include <vector>
using namespace std;

vector<int> printNos(int n) {
    vector<int> result;
    if (n < 1) {
        return result; // Return an empty vector when n < 1
    }
    result = printNos(n - 1); // Recursively call with n - 1
    result.push_back(n); // Add the current value of n to the vector
    return result;
}

int main() {
    int n = 5; // Example: Change this to the desired value of n
    vector<int> result = printNos(n);
    
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}