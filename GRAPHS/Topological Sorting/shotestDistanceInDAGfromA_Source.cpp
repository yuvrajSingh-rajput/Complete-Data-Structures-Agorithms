#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int node, vector<int>& vis, vector<pair<int, int>> adj[], stack<int>& st){
        vis[node] = true;
        
        for(auto it: adj[node]){
            if(!vis[it.first])
                dfs(it.first, vis, adj, st);
        }
        
        st.push(node);
    }
  public:
     vector<int> shortestPath(int N, int M, vector<vector<int>>& edges){
        // CREATE A GRAPH
        vector<pair<int, int>> adj[N];
        for(int i = 0; i < M; i++){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v, w});
        }
        
        // TOPOLOGICAL SORTING
        stack<int> st;
        vector<int> vis(N, false);
        for(int i = 0; i < N; i++){
            if(!vis[i])
                dfs(i, vis, adj, st);
        }
        
        // CREATE A DISTANCE ARRAY WITH EVERY DISTANCE FROM SOURCE AS INFINITE.
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;
        
        // PROCESSING NODES IN TOPOLOGICAL ORDER
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(dist[node] != INT_MAX) { // If the node has been reached
                for(auto it: adj[node]){
                    int v = it.first, w = it.second;
                    
                    if(dist[v] > dist[node] + w){
                        dist[v] = dist[node] + w;
                    }
                }
            }
        }
        
        // Replace all INT_MAX values with -1 to indicate unreachable nodes
        for(int i = 0; i < N; i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        
        return dist;
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