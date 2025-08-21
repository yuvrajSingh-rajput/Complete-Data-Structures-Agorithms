class Solution {
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& arr){
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int k = i; k < j; k++){
            int curr = arr[i - 1] * arr[k] * arr[j]; // important to notice this pattern 
            ans = min(ans, curr + solve(i, k, arr) + solve(k + 1, j, arr));
        }
        return dp[i][j] = ans;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(1, n - 1, arr);
    }
};
