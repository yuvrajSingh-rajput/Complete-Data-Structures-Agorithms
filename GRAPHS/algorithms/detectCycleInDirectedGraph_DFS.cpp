#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool dfsCheck(int node, vector<int> adj[], vector<bool>& vis, vector<bool>&pathVis){
        vis[node] = true;
        pathVis[node] = true;
        
        for(auto adjacentNodes : adj[node]){
            if(!vis[adjacentNodes]){
            
                if(dfsCheck(adjacentNodes, adj, vis, pathVis)) return true;
                
            }else if(pathVis[adjacentNodes]) return true;
                
        }
        
        pathVis[node] = false;
        
        return false;
    }
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, false), pathVis(V, false);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfsCheck(i, adj, vis, pathVis)) return true;
            }
        }
        return false;
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