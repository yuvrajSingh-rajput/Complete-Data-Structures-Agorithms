#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        vector<int> result;
        int carry = 1; // Start with a carry of 1 to add one
        
        for(int i = size - 1; i >= 0; i--){
            int sum = digits[i] + carry;
            carry = sum / 10; // Calculate the new carry
            result.push_back(sum % 10); // Push the current digit
        }
        
        // If there's still a carry left after the loop, add it as a new digit
        if (carry > 0) {
            result.push_back(carry);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
