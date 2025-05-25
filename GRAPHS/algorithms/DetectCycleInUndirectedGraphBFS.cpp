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


