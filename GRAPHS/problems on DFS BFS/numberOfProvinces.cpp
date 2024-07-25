#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, int source, vector<bool> &vis){
    vis[source] = true;

    for(int i = 0; i < graph[source].size(); i++)
        if (graph[source][i] && !vis[i])
            dfs(graph, i, vis);
}

int totalProvinces(vector<vector<int>>& graph){
    vector<bool> vis(graph.size(), false);
    int ans = 0;
    for(int start = 0; start < graph.size(); start++){
        if(!vis[start]){
            ans++;
            dfs(graph, start, vis);
        }
    }
    return ans;
}

void solve(void){
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for(auto &row : graph)
        for(auto &col : row) cin >> col;

    cout << totalProvinces(graph) << endl;
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
