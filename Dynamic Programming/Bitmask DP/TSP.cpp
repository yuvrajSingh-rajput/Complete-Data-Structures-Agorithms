class Solution {
    vector<vector<int>> dp;
    
    int solve(int city, int mask, vector<vector<int>>& cost) {
        if (mask == 0) { 
            return cost[city][0];
        }

        if (dp[city][mask] != -1) return dp[city][mask];

        int ans = INT_MAX;
        int n = cost.size();

        for (int next = 0; next < n; next++) {
            if (mask & (1 << next)) {
                int newMask = mask ^ (1 << next);
                int candidate = cost[city][next] + solve(next, newMask, cost);
                ans = min(ans, candidate);
            }
        }

        return dp[city][mask] = ans;
    }

public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        dp.assign(n, vector<int>(1 << n, -1));
        
        int mask = (1 << n) - 1;
        mask ^= 1; 

        return solve(0, mask, cost);
    }
};
