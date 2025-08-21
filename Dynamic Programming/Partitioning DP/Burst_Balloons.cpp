class Solution {
    vector<vector<int>> dp;
private:
    int MCM(int i, int j, vector<int>& nums){
        if(i == j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MIN;
        for(int k = i; k < j; k++){
            int curr = nums[i - 1] * nums[k] * nums[j];
            ans = max(ans, curr + MCM(i, k, nums) + MCM(k + 1, j, nums));
        }

        return dp[i][j] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        dp.assign(n, vector<int>(n, -1));
        // we created the MCM pattern.
        return MCM(1, n - 1, nums);
    }
};
