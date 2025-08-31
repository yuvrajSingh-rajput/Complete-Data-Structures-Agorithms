class Solution {
    vector<int> dp;
    vector<pair<pair<int, int>, int>> arr; 
    int n;
    
    int solve(int i) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        int not_take = solve(i + 1);

        int nextIdx = lower_bound(arr.begin(), arr.end(), arr[i].first.second, 
            [](const pair<pair<int,int>,int>& p, int val) {
                return p.first.first < val; 
            }) - arr.begin();

        int take = arr[i].second + solve(nextIdx);

        return dp[i] = max(take, not_take);
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = profit.size();
        arr.clear();
        for (int i = 0; i < n; i++) {
            arr.push_back({{startTime[i], endTime[i]}, profit[i]});
        }

        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            return a.first.first < b.first.first;
        });

        dp.assign(n, -1);
        return solve(0);
    }
};
