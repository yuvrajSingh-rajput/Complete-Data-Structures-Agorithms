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
    cin.tie(nullptr);
    auto _clock_start = chrono::high_resolution_clock::now();


    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif

    auto solve = [&]() -> void {
        ll n, q;
        cin >> n >> q;

        vector<vector<ll>> tree(n);
        vector<ll> parent(n, -1);
        parent[0] = -1;

        for(ll i = 1; i < n; i++){
            cin >> parent[i];
            parent[i] --;
            tree[parent[i]].push_back(i);
        }

        vector<ll> depth(n, 0);
        function<void(ll, ll)> dfs = [&](ll node, ll par) {
            for(auto child: tree[node]){
                if(child != par){
                    depth[child] = depth[node] + 1;
                    dfs(child, node);
                }
            }
        };

        // Pre-Processing
        ll LOG = 0;
        while(1 << LOG <= n) LOG ++;

        vector<vector<ll>> up(n, vector<ll>(LOG, -1));

        for(ll i = 0; i < n; i++){
            up[i][0] = parent[i];
        }

        for(ll j = 1; j < LOG; j++){
            for(ll i = 0; i < n; i++){
                if(up[i][j - 1] != -1) {
                    up[i][j] = up[up[i][j - 1]][j - 1];
                }
            }
        }

        dfs(0, -1);

        // LCA function
        auto getLCA = [&](ll u, ll v) -> ll {
            if(depth[u] < depth[v]) swap(u, v);

            // Lift u to the depth of v;
            for(ll j = LOG - 1; j >= 0; j --){
                if(depth[u] - (1 << j) >= depth[v]){
                    u = up[u][j];
                }
            }

            // now both are at the same level
            if(u == v) return u;

            // lift until their parents matches
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

            cout << getLCA(a, b) + 1 << endl;
        }
    };

    solve();

    auto _clock_end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(_clock_end - _clock_start).count();
    cerr << "Execution time: " << duration << " ms." << endl;

    return 0;
}
