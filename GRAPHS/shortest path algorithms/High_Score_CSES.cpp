#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using ll = long long;
const ll mod = 1e9+7;
const ll INF = 1e18;
#define endl "\n";
using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
signed main(int argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
       
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif
 
    auto solve = [&]() -> void {
        int n, m;
        cin >> n >> m;

        vector<tuple<int, int, ll>> edges;
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < m; ++i) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            adj[u].push_back(v); 
        }

        vector<ll> dist(n + 1, -INF);
        dist[1] = 0;

        for (int i = 1; i <= n - 1; ++i) {
            for (auto [u, v, w] : edges) {
                if (dist[u] != -INF && dist[u] + w > dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        vector<int> affected;
        for (auto [u, v, w] : edges) {
            if (dist[u] != -INF && dist[u] + w > dist[v]) {
                affected.push_back(v);
            }
        }

        vector<bool> visited(n + 1, false);
        queue<int> q;
        for (int node : affected) {
            q.push(node);
            visited[node] = true;
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        if (visited[n]) {
            cout << -1 << '\n';
        } else {
            cout << dist[n] << '\n';
        }
    };
 
    solve();
 
    return 0;
}
