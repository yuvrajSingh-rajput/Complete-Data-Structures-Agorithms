/*
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
 

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false

*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long prefSum = 0;
        unordered_map<int, int> mpp;
        mpp[0] = -1; 

        for (int i = 0; i < nums.size(); i++) {
            prefSum += nums[i];
            
            int temp = prefSum % k;
            if (temp < 0) temp += k; 
            
            if (mpp.find(temp) != mpp.end()) {
                if (i - mpp[temp] >= 2) return true;
            } else {
                mpp[temp] = i;
            }
        }
        return false;
    }
};


#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
    cin.tie(nullptr);
    #endif

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    return 0;
}
