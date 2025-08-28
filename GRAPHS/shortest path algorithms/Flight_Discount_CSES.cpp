#include<bits/stdc++.h>
using ll = long long;
using namespace std;

signed main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);

    auto solve = [&]() -> void {
        ll n, m;
        cin >> n >> m;

        vector<vector<pair<ll, ll>>> adj(n);
        for (ll i = 0; i < m; i++) {
            ll u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            adj[u].push_back({v, w});
        }

        const ll INF = 1e18;
        vector<vector<ll>> dist(n, vector<ll>(2, INF));
        dist[0][0] = 0;

        priority_queue<tuple<ll,ll,int>, vector<tuple<ll,ll,int>>, greater<>> pq;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [d, u, used] = pq.top();
            pq.pop();
            if (d != dist[u][used]) continue;

            for (auto [v, w] : adj[u]) {
                // Case 1: normal edge (no discount)
                if (d + w < dist[v][used]) {
                    dist[v][used] = d + w;
                    pq.push({dist[v][used], v, used});
                }
                // Case 2: use discount on this edge (if not used yet)
                if (!used && d + w/2 < dist[v][1]) {
                    dist[v][1] = d + w/2;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }

        cout << min(dist[n-1][0], dist[n-1][1]) << "\n";
    };

    solve();

    return 0;
}
