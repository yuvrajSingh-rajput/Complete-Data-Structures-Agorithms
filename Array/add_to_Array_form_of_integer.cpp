#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    std::vector<int> addToArrayForm(std::vector<int>& num, int k) {
        int size = num.size();
        std::vector<int> result;
        int carry = k;

        for (int i = size - 1; i >= 0 || carry > 0; i--) {
            if (i >= 0) {
                carry += num[i];
            }
            result.push_back(carry % 10);
            carry /= 10;
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};
