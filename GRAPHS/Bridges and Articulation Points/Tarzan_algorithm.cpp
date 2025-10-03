class Solution {
    vector<vector<int>> adj, ans;
    vector<int> vis;
    vector<int> tin;
    vector<int> low;
    int timer;
  private:
    void dfs(int node, int parent){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        
        for(auto it: adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it, node);
                low[node] = min(low[node], low[it]);
                // check for the bridge
                if(low[it] > tin[node]) {
                    vector<int> temp = {node, it};
                    ans.push_back(temp);
                }
            }else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
  public:
    vector<vector<int>> criticalConnections(int v, vector<vector<int>>& edges) {
        adj.resize(v);
        for(auto it: edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vis.assign(v, 0);
        tin.resize(v);
        low.assign(v, INT_MAX);
        this->timer = 0;
        dfs(0, -1);
        return ans;
    }
};
