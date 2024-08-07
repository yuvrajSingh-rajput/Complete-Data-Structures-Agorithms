#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int i, int j, vector<vector<char>>& mat, vector<vector<bool>>& vis, int delRow[], int delCol[]) {
        int n = mat.size(), m = mat[0].size();
        vis[i][j] = true;
        
        for (int dir = 0; dir < 4; dir++) { 
            int x = i + delRow[dir], y = j + delCol[dir];

            
            if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && mat[x][y] == 'O') {
                dfs(x, y, mat, vis, delRow, delCol); 
            }
        }
    }

public:
    void solve(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false)); 
        int delRow[] = {-1, 0, 1, 0}; 
        int delCol[] = {0, 1, 0, -1}; 

        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && mat[0][j] == 'O') {
                dfs(0, j, mat, vis, delRow, delCol);
            }
            if (!vis[n - 1][j] && mat[n - 1][j] == 'O') {
                dfs(n - 1, j, mat, vis, delRow, delCol);
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, mat, vis, delRow, delCol);
            }
            if (!vis[i][m - 1] && mat[i][m - 1] == 'O') {
                dfs(i, m - 1, mat, vis, delRow, delCol);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }

        return;
    }
};

signed main(int argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        cin.tie(nullptr);
        auto _clock_start = chrono::high_resolution_clock::now();
    #endif

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    

    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        auto _clock_end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(_clock_end-_clock_start).count();
        cerr << "Execution time: " << duration << " ms." << endl;
    #endif

    return 0;
}