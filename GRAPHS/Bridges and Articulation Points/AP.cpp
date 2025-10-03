class Solution {
    vector<int> vis, tin, low, mark;
    int timer;
    
    void dfs(int node, int parent, vector<int> adj[]){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        
        int child = 0;
        for(auto it: adj[node]){
            if(it == parent) continue;
            
            if(!vis[it]){
                dfs(it, node, adj);
                low[node] = min(low[node], low[it]);
                
                // Non-root articulation condition
                if(low[it] >= tin[node] && parent != -1){
                    mark[node] = 1;
                }
                child++;
            } else {
                // Back edge
                low[node] = min(low[node], tin[it]);
            }
        }
        
        // Root articulation condition
        if(parent == -1 && child > 1){
            mark[node] = 1;
        }
    }
    
public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vis.assign(V, 0);
        tin.resize(V);
        low.assign(V, INT_MAX);
        mark.assign(V, 0);
        timer = 0;
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, -1, adj);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(mark[i]) ans.push_back(i);
        }
        if(ans.empty()) return {-1};
        return ans;
    }
};
