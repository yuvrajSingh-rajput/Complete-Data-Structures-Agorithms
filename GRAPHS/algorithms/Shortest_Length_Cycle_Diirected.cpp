class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges)
            adj[e[0]].push_back(e[1]); // directed edge

        int ans = INT_MAX;

        for (int start = 0; start < n; ++start) {
            vector<int> dist(n, -1);
            queue<int> q;
            dist[start] = 0;
            q.push(start);

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    } else if (v == start) {
                        // We found a cycle ending back at the start node
                        ans = min(ans, dist[u] + 1);
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

