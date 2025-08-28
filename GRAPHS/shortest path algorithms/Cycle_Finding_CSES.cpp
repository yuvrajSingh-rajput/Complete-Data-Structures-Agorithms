#include <bits/stdc++.h>
using ll = long long;
using namespace std;

signed main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
#ifndef YUVRAJ_SINGH_RAJPUT
    cin.tie(nullptr);
    auto _clock_start = chrono::high_resolution_clock::now();
#endif

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    auto solve = [&]() -> void
    {
        ll n, e;
        cin >> n >> e;
        vector<tuple<ll, ll, ll>> edges;
        for (int i = 0; i < e; i++)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u-1, v-1, w});
        }

        vector<ll> dist(n, 1e15), parent(n, -1);
        dist[0] = 0;
        ll x = -1;

        for (int i = 0; i < n - 1; i++)
        {
            for (auto [u, v, w] : edges)
            {
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }
            }
        }

        for (auto [u, v, w] : edges)
        {
            if (dist[u] + w < dist[v])
            {
                parent[v] = u;
                x = v;
                break;
            }
        }

        if (x == -1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
            {
                x = parent[x];
            }

            vector<ll> cycle;
            for (ll cur = x;; cur = parent[cur])
            {
                cycle.push_back(cur);
                if (cur == x && cycle.size() > 1)
                    break;
            }
            reverse(cycle.begin(), cycle.end());

            for (auto node : cycle)
                cout << node + 1 << " ";
            cout << "\n";
        }
    };

    ll t = 1;
    while (t--)
        solve();

#ifndef YUVRAJ_SINGH_RAJPUT
    auto _clock_end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(_clock_end - _clock_start).count();
    cerr << "Execution time: " << duration << " ms." << endl;
#endif
    return 0;
}
