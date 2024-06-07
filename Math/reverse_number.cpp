#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long int sum = 0; // Use a long long to store the result to handle potential overflow
        while (x != 0) {
            sum = sum * 10 + (x % 10);
            x = x / 10;
        }
        if (sum > INT_MAX || sum < INT_MIN) {
            return 0; // Handle overflow by returning 0
        }
        return static_cast<int>(sum); // Convert the result back to int and return it
    }
};