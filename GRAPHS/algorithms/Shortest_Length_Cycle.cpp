class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        // lets create a adjancency list
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = INT_MAX;
        for(int node = 0; node < n; node++){
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);
            queue<int> q;

            dist[node] = 0;
            q.push(node);

            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(int v: adj[u]){
                    if(dist[v] == -1){ // not visited
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    }else if(parent[u] != v){ // visited -> found a cycle
                        ans = min(ans, dist[u] + dist[v] + 1);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
