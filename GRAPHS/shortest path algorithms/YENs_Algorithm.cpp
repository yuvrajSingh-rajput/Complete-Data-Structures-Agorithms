#include<bits/stdc++.h>
using ll = long long;
#define endl "\n";
using namespace std;

signed main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    
    auto solve = [&]() -> void {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<vector<pair<ll, ll>>> adj(n);
        for(ll i = 0; i < m; i++){
            ll u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            adj[u].push_back({v, w});
        }
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, 0});

        vector<ll> count(n, 0);
        vector<ll> ans;

        while(!pq.empty() && ans.size() < k){
            auto [d, u] = pq.top();
            pq.pop();

            count[u]++;
            if(u == n - 1) ans.push_back(d);

            if(count[u] > k) continue;  // main condition

            for(auto it: adj[u]){
                auto [v, w] = it;
                pq.push({d + w, v});
            }
        }

        for(auto dist: ans){
            cout << dist << " ";
        }

        cout << endl;
    };

    solve();
  
    return 0;
}
