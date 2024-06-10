/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

*/
#include<bits/stdc++.h>
using ll = long long;
const long double pi=3.141592653589793238462;
const long long mod = 1e9+7;
using namespace std;

//FUNCTION START HERE...........

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0, prefoc = 0;
        unordered_map<int, int> mpp;
        mpp[0] ++;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & 1)
                prefoc ++;
            if(mpp.find(prefoc - k) != mpp.end())
                ans += mpp[prefoc - k];
            mpp[prefoc]++;
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

    solve();
    return 0;
}
