class Solution {
private:
    set<string> getAllLCS(string& text1, string& text2, int i, int j,
                         vector<vector<int>>& dp, 
                         unordered_map<string, set<string>>& memo,
                         int lcsLength) {
        string key = to_string(i) + "," + to_string(j);
        
        if (memo.count(key)) {
            return memo[key];
        }
        
        set<string> result;
        
        if (i == 0 || j == 0) {
            result.insert("");
            memo[key] = result;
            return result;
        }
        
        if (text1[i-1] == text2[j-1]) {
            set<string> subLCS = getAllLCS(text1, text2, i-1, j-1, dp, memo, lcsLength);
            for (const string& subseq : subLCS) {
                result.insert(subseq + text1[i-1]);
            }
        } else {
            if (dp[i-1][j] >= dp[i][j-1]) {
                set<string> up = getAllLCS(text1, text2, i-1, j, dp, memo, lcsLength);
                result.insert(up.begin(), up.end());
            }
            if (dp[i][j-1] >= dp[i-1][j]) {
                set<string> left = getAllLCS(text1, text2, i, j-1, dp, memo, lcsLength);
                result.insert(left.begin(), left.end());
            }
        }
        
        int remainingChars = lcsLength - dp[i][j];
        set<string> filtered;
        for (const string& seq : result) {
            if (seq.length() + remainingChars >= lcsLength) {
                filtered.insert(seq);
            }
        }
        
        memo[key] = filtered;
        return filtered;
    }

public:
    vector<string> all_longest_common_subsequences(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        int lcsLength = dp[n][m];
        unordered_map<string, set<string>> memo;
        
        set<string> lcsSet = getAllLCS(text1, text2, n, m, dp, memo, lcsLength);
        
        vector<string> result(lcsSet.begin(), lcsSet.end());
        return result;
    }
};
