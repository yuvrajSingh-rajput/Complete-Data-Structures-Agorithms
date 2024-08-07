#include<bits/stdc++.h>
using namespace std;

class Solution{
    void bfs(int i, int j, vector<vector<char>> mat, vector<vector<bool>>& vis, int delRow[], int delCol[]){
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        vis[i][j] = true;
        q.push({i, j});
        
        while(!q.empty()){
            int u = q.front().first, v= q.front().second;
            q.pop();
            
            for(int k = 0; k < 4; k++){
                int x = u + delRow[k], y = v + delCol[k];
                
                if(x < n && y < m && x >= 0 && y >= 0 && !vis[x][y] && mat[x][y] == 'O'){
                    vis[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> ans(n, vector<char>(m));
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};
        
        for(int j = 0; j < m; j++)
            if(!vis[0][j] && mat[0][j] == 'O')
                bfs(0, j, mat, vis, delRow, delCol);
        
        for(int j = 0; j < m; j++)
            if(!vis[n - 1][j] && mat[n - 1][j] == 'O')
                bfs(n - 1, j, mat, vis, delRow, delCol);
        
        for(int i = 0; i < n; i++)
            if(!vis[i][0] && mat[i][0] == 'O')
                bfs(i, 0, mat, vis, delRow, delCol);
                
        for(int i = 0; i < n; i++)
            if(!vis[i][m - 1] && mat[i][m - 1] == 'O')
                bfs(i, m - 1, mat, vis, delRow, delCol);
                
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!vis[i][j] && mat[i][j] == 'O') ans[i][j] = 'X';
                else ans[i][j] = mat[i][j];
                
        return ans;
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