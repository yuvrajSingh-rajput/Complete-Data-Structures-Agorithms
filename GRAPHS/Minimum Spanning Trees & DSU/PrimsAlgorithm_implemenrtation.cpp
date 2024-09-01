class Solution
{
	public:
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<bool> vis(V, false);
        pq.push({0, {0, -1}});
        
        int ans = 0;
        vector<pair<int, int>> mst;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int wt = it.first, node = it.second.first, parent = it.second.second;
            
            if(vis[node]) continue;
            
            vis[node] = true;
            ans += wt;
            mst.push_back({parent, node});
            
            for(auto it: adj[node]){
                int adjNode = it[0], edgeWt = it[1];
                
                if(!vis[adjNode]) {
                    pq.push({edgeWt, {adjNode, node}});
                }
            }
        }
        return ans;
    }
};
