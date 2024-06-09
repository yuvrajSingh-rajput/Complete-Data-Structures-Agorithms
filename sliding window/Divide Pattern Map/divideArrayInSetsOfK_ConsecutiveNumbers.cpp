/*
Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.

Return true if it is possible. Otherwise, return false.

Example 1:

Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
Example 2:

Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
Example 3:

Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.
*/

#include<bits/stdc++.h>
using ll = long long;
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        unordered_map<int, int> mpp;
        vector<int> arr;
        
        for (int i = 0; i < hand.size(); i++) {
            if (mpp.find(hand[i]) == mpp.end())
                arr.push_back(hand[i]);
            mpp[hand[i]]++;
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
            if (mpp[arr[i]] == 0)
                continue;

            for (int j = 0; j < groupSize; j++) {
                int current = arr[i] + j;
                if (mpp[current] == 0)
                    return false;
                mpp[current]--;
            }
            i--;
        }

        return true;
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
