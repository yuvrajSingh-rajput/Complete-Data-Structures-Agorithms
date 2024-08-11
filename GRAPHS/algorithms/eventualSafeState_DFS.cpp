#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool detectCycle(int node, vector<bool>& vis, vector<int> adj[], vector<bool>& pathVis, vector<bool>& isSafe) {
        vis[node] = true;
        pathVis[node] = true;
        
        for(auto &adjNode: adj[node]){
            if(!vis[adjNode]){
                if(detectCycle(adjNode, vis, adj, pathVis, isSafe)) return true;
            } else if(pathVis[adjNode]) return true;
        }
        
        isSafe[node] = true;
        pathVis[node] = false;
        return false;
    }
    
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<bool> isSafe(V, false);
        vector<bool> pathVis(V, false);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                detectCycle(i, vis, adj, pathVis, isSafe);
            }
        }
        
        vector<int> result;
        for(int i = 0; i < V; i++){
            if(isSafe[i]) result.push_back(i);
        }
        
        return result;
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