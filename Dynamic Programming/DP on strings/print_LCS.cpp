class Solution {
public:
    vector<string> all_longest_common_subsequences(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> LCS(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    LCS[i][j] = 1 + LCS[i - 1][j - 1];
                else
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
        int len = LCS[n][m];

        vector<vector<set<string>>> dp(n + 1, vector<set<string>>(m + 1));
        
        for (int i = 0; i <= n; i++) dp[i][0].insert("");
        for (int j = 0; j <= m; j++) dp[0][j].insert("");
        

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    for (const string& s : dp[i - 1][j - 1]) {
                        dp[i][j].insert(s + text1[i - 1]);
                    }
                }
                else{
                    dp[i][j].insert(dp[i - 1][j].begin(), dp[i - 1][j].end());
                    dp[i][j].insert(dp[i][j - 1].begin(), dp[i][j - 1].end());
                }
            }
        }

        vector<string> ans;
        for (const string& s : dp[n][m]) {
            if (s.length() == len) {
                ans.push_back(s);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};
