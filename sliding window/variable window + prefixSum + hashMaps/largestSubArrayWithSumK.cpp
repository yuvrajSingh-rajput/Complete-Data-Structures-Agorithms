#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int getLongestSubarray(vector<int>& nums, int k){
    long long prefSum = 0;
    int ans = 0;
    unordered_map<long long, int> mpp;
    for(int i = 0; i < nums.size(); i++){
        prefSum += nums[i];
        if(prefSum == k){
            ans = max(ans, i + 1);
        }
        int temp = prefSum - k;
        if(mpp.find(temp) != mpp.end()){
            int len = i - mpp[temp];
            ans = max(ans, len);
        }
        // to handle the zero.
        if(mpp.find(prefSum) == mpp.end()){
            mpp[prefSum] = i;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // this method is optimal for both array containing positive and negative numbers;
    return 0;
}