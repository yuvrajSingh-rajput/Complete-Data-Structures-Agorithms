#include<bits/stdc++.h>
using ll = long long;
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        ll prefSum = 0;
        int ans = 0;
        unordered_map<ll, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            prefSum += nums[i];
            if (prefSum == k) {
                ans ++;
            }
            int temp = prefSum - k;
            if (mpp.find(temp) != mpp.end()) {
                ans += mpp[temp];
            }
            mpp[prefSum]++;
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // for both posive and negative numbers.
    return 0;
}