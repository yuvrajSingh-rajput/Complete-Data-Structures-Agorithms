// top down approach
class Solution {
    vector<vector<int>> dp;
    int LCS(int index1, int index2, string text1, string text2){
        if(index1 < 0 or index2 < 0) return 0;

        if(dp[index1][index2] != -1) return dp[index1][index2];

        if(text1[index1] == text2[index2]){
            return dp[index1][index2] = 1 + LCS(index1 - 1, index2 - 1, text1, text2);
        }
        return dp[index1][index2] = max(LCS(index1 - 1, index2, text1, text2), LCS(index1, index2 - 1, text1, text2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        dp.clear();
        int n = text1.length();
        int m = text2.length();
        dp.assign(n, vector<int>(m, - 1));
        return LCS(n - 1, m - 1, text1, text2);
    }
};

// bottom up approach
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];

                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};
