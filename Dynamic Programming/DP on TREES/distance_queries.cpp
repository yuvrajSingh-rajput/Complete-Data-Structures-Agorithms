#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using ll = long long;
#define endl "\n";
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    #ifndef FAST_IO
        cin.tie(nullptr);
        auto _clock_start = chrono::high_resolution_clock::now();
    #endif

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    auto solve = [&]() -> void {
        ll n, q;
        cin >> n >> q;

        vector<vector<ll>> tree(n);

        for(ll i = 1; i < n; i++){
            ll u, v;
            cin >> u >> v;
            u --;
            v --;
            tree[v].push_back(u);
            tree[u].push_back(v);
        }

        // Pre-Processing
        ll LOG = 0;
        while(1 << LOG <= n) LOG ++;
        
        vector<ll> depth(n, 0);
        vector<vector<ll>> up(n, vector<ll>(LOG, -1));

        function<void(ll, ll)> dfs = [&](ll node, ll par) {
            up[node][0] = par;
            for (int i = 1; i < LOG; ++i) {
                if (up[node][i - 1] != -1)
                    up[node][i] = up[up[node][i - 1]][i - 1];
            }
            for (int child : tree[node]) {
                if (child != par) {
                    depth[child] = depth[node] + 1;
                    dfs(child, node);
                }
            }
        };
        dfs(0, -1);

        // LCA function
        auto getLCA = [&](ll u, ll v) -> ll {
            if(depth[u] < depth[v]) swap(u, v);

            for(ll j = LOG - 1; j >= 0; j --){
                if(depth[u] - (1 << j) >= depth[v]){
                    u = up[u][j];
                }
            }

            if(u == v) return u;

            for(ll j = LOG - 1; j >= 0; j--){
                if(up[u][j] != -1 && up[u][j] != up[v][j]){
                    u = up[u][j];
                    v = up[v][j];
                }
            }

            return up[u][0];
        };


        // Queries
        for(ll i = 0; i < q; i++){
            ll a, b;
            cin >> a >> b;
            a--;
            b --;
            
            cout << depth[a] + depth[b] - 2 * depth[getLCA(a, b)] << endl;
        }
    };

    solve();
  
    return 0;
}
