/*
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
Example 2:

Input: nums = [5], k = 9
Output: 0

*/

#include<bits/stdc++.h>
using ll = long long;
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int prefSum = 0, ans = 0;
        mpp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            prefSum += nums[i];
            
            int temp = (prefSum % k + k) % k;

            if(mpp.find(temp) != mpp.end()){
                ans += mpp[temp];
            }

            mpp[temp] ++;
        }
        return ans;
    }
};

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