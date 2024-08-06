#include<bits/stdc++.h>
using namespace std;

bool detectCycle(int src, vector<int> adj[], int V, vector<bool>& vis){
        queue<pair<int, int>> q;
        q.push({src, -1});
        while(!q.empty()){
            int node = q.front().first, parent = q.front().second;
            q.pop();
            for(auto adjecentNode: adj[node]){
                if(!vis[adjecentNode]) q.push({adjecentNode, node});
                else if(adjecentNode != parent) return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        // what if graph has connected components.
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                bool ans = detectCycle(i, adj, V, vis);
                if(ans) return true;
            }
        }
        return false;
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

    

    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        auto _clock_end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(_clock_end-_clock_start).count();
        cerr << "Execution time: " << duration << " ms." << endl;
    #endif

    return 0;
}