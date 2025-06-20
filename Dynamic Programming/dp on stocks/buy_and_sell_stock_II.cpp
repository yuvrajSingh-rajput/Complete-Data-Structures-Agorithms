class Solution {
    vector<vector<int>> dp;
private:
    int maxProfitHelper(vector<int>& prices, int buy, int i){
        if(i == prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if(!buy){
            profit = max(-prices[i] + maxProfitHelper(prices, 1, i + 1), maxProfitHelper(prices, 0, i + 1));
        }else {
            profit = max(prices[i] + maxProfitHelper(prices, 0, i + 1), maxProfitHelper(prices, 1, i + 1));
        }

        return dp[i][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n + 1, vector<int>(2, -1));
        return maxProfitHelper(prices, 0, 0);
    }
};
