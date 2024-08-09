#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(int node, vector<int> adj[], vector<int>& color, int curr_col){
        color[node] = curr_col;
        for(auto adjacentNode: adj[node]){
            if(color[adjacentNode] == -1){
                if(!dfs(adjacentNode, adj, color, !curr_col)){
                    return false;
                }
            } 
            else if(color[adjacentNode] == curr_col) {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(int V, vector<int>adj[]){
        vector<int> color(V, -1);
        for(int i = 0; i < V; i++){
            if(color[i] == -1){
                bool ans = dfs(i, adj, color, 0);
                if(!ans) return false;
            }
        }
        return true;
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