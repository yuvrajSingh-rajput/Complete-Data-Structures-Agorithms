/* Advantages:
1. all shortest path from a single source to every node
2. detect negative weight cycles, which overcomes the problem of dijsktra algorithm.
*/

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        // N - 1 iteration
        for(int i = 0; i < V - 1; i++){
            for(auto it: edges){
                int u = it[0], v = it[1], wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // Nth iteration to detect if any negative cycle;
        for(auto it : edges){
            int u = it[0], v = it[1], wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};


// time complexity = O(V * E)
// space complexity = O(V)
