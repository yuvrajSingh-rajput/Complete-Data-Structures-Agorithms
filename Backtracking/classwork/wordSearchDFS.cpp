#include<bits/stdc++.h>
using ll = long long;
const long double pi=3.141592653589793238462;
const long long mod = 1e9+7;
using namespace std;

class Solution {
    bool existHelper(int i, int j, int idx, vector<vector<char>>& board, string curr, string& word, vector<vector<bool>>& vis){
        if(curr == word){
            return true;
        }
        
        // Checking boundary conditions and visited cells
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || vis[i][j] || board[i][j] != word[idx]) {
            return false;
        }
        
        // Marking current cell as visited
        vis[i][j] = true;
        
        // Right
        if(existHelper(i, j + 1, idx + 1, board, curr + board[i][j], word, vis))
            return true;
        // Left
        if(existHelper(i, j - 1, idx + 1, board, curr + board[i][j], word, vis))
            return true;
        // Bottom
        if(existHelper(i + 1, j, idx + 1, board, curr + board[i][j], word, vis))
            return true;
        // Up
        if(existHelper(i - 1, j, idx + 1, board, curr + board[i][j], word, vis))
            return true;
        
        // Unmark current cell as visited
        vis[i][j] = false;
        
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(existHelper(i, j, 0, board, "", word, vis))
                    return true;
            }
        }
        return false;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    return 0;
}