//Non-hamiltonion
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int,int>> q; // {node, mask}
        vector<vector<int>> dist(n, vector<int>(1<<n, -1));
        
        // Multi-source BFS: start from all nodes
        for(int i = 0; i < n; i++){
            q.push({i, 1<<i});
            dist[i][1<<i] = 0;
        }
        
        while(!q.empty()){
            auto [u, mask] = q.front(); q.pop();
            
            if(mask == (1<<n) - 1) return dist[u][mask]; 
            
            for(int v : graph[u]){
                int newMask = mask | (1<<v);
                if(dist[v][newMask] == -1){
                    dist[v][newMask] = dist[u][mask] + 1;
                    q.push({v, newMask});
                }
            }
        }
        
        return 0; 
    }
};
