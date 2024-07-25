#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>>& graph, vector<vector<bool>>& vis, int i, int j) {
    int n = graph.size(), m = graph[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;

    while (!q.empty()) {
        int u = q.front().first, v = q.front().second;
        q.pop();

        // Explore all 8 directions (up, down, left, right, and diagonals)
        if (u + 1 < n && !vis[u + 1][v] && graph[u + 1][v] == '1')
            q.push({u + 1, v}), vis[u + 1][v] = true;
        if (u - 1 >= 0 && !vis[u - 1][v] && graph[u - 1][v] == '1')
            q.push({u - 1, v}), vis[u - 1][v] = true;
        if (v + 1 < m && !vis[u][v + 1] && graph[u][v + 1] == '1')
            q.push({u, v + 1}), vis[u][v + 1] = true;
        if (v - 1 >= 0 && !vis[u][v - 1] && graph[u][v - 1] == '1')
            q.push({u, v - 1}), vis[u][v - 1] = true;
        if (u + 1 < n && v + 1 < m && !vis[u + 1][v + 1] && graph[u + 1][v + 1] == '1')
            q.push({u + 1, v + 1}), vis[u + 1][v + 1] = true;
        if (u + 1 < n && v - 1 >= 0 && !vis[u + 1][v - 1] && graph[u + 1][v - 1] == '1')
            q.push({u + 1, v - 1}), vis[u + 1][v - 1] = true;
        if (u - 1 >= 0 && v + 1 < m && !vis[u - 1][v + 1] && graph[u - 1][v + 1] == '1')
            q.push({u - 1, v + 1}), vis[u - 1][v + 1] = true;
        if (u - 1 >= 0 && v - 1 >= 0 && !vis[u - 1][v - 1] && graph[u - 1][v - 1] == '1')
            q.push({u - 1, v - 1}), vis[u - 1][v - 1] = true;
    }
}

int nIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size(), ans = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && grid[i][j] == '1') {
                ans++;
                bfs(grid, vis, i, j);
            }
        }
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    for (auto &row : grid) {
        for (auto &col : row) {
            cin >> col;
        }
    }

    cout << nIslands(grid) << endl;
}

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

    solve();

    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        auto _clock_end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(_clock_end-_clock_start).count();
        cerr << "Execution time: " << duration << " ms." << endl;
    #endif

    return 0;
}
