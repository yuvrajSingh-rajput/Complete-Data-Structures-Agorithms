#include<bits/stdc++.h>
using ll = long long;
const long double pi=3.141592653589793238462;
const long long mod = 1e9+7;
using namespace std;

class Solution {
    bool existHelper(int i, int j, int idx, vector<vector<char>>& board, string& curr, const string& word, vector<vector<bool>>& vis) {
        // If the current string matches the target word, return true
        if (curr == word)
            return true;

        // Check boundary conditions and whether the cell has been visited
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || vis[i][j] || board[i][j] != word[idx])
            return false;

        // Mark the current cell as visited
        vis[i][j] = true;

        // Update the current string by appending the current character
        curr.push_back(board[i][j]);

        // Explore neighboring cells in all four directions
        bool found = existHelper(i + 1, j, idx + 1, board, curr, word, vis) ||
                     existHelper(i - 1, j, idx + 1, board, curr, word, vis) ||
                     existHelper(i, j + 1, idx + 1, board, curr, word, vis) ||
                     existHelper(i, j - 1, idx + 1, board, curr, word, vis);

        // Backtrack: unmark the current cell as visited and remove the last character from the current string
        vis[i][j] = false;
        curr.pop_back();

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();

        // Initialize a 2D array to keep track of visited cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Iterate through each cell in the board
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                string curr = ""; // Initialize the current string
                // Check if the word can be found starting from the current cell
                if (existHelper(i, j, 0, board, curr, word, visited))
                    return true;
            }
        }
        return false; // If the word cannot be found starting from any cell
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