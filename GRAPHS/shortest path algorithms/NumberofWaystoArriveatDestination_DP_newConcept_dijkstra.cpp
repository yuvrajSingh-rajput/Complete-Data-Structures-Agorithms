class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto& road : roads){
            int u = road[0], v = road[1], w = road[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        vector<int> dist(n, INT_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0);
        
        while(!pq.empty()){
            auto [d, u] = pq.top(); pq.pop();
            
            if(d > dist[u]) continue;
            
            for(auto& [v, w] : graph[u]){
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;   
                    ways[v] = ways[u];       // optimised approach...
                    pq.emplace(dist[v], v);
                }
                else if(dist[u] + w == dist[v]){
                    ways[v] += ways[u];     // ------->>>>
                }
            }
        }
        
        return ways[n - 1];
    }
};
