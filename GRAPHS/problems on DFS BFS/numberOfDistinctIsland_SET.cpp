#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis, vector<pair<int, int>>& store, int row0, int col0){
        vis[row][col] = true;
        int n = grid.size(), m = grid[0].size();
        store.push_back({row - row0, col - col0});
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        
        for(int i = 0; i < 4; i++){
            int u = row + delrow[i], v = col + delcol[i];
            
            if(u >= 0 && u < n && v >= 0 && v < m && !vis[u][v] && grid[u][v] == 1)
                dfs(u, v, grid, vis, store, row0, col0);
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        set<vector<pair<int, int>>> st;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>> store;
                    dfs(i, j, grid, vis, store, i, j);
                    st.insert(store);
                }
            }
        }
        return st.size();
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