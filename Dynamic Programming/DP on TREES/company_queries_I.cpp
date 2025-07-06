#include<bits/stdc++.h>
using ll = long long
#define endl "\n";
using namespace std;

signed main(int argc, char* argv[]) {
    auto solve = [&]() -> void {
        ll n, q;
        cin >> n >> q;
        vector<ll> parent(n, -1);
        parent[0] = -1;
        for(ll i = 1; i < n; i++){
            cin >> parent[i];
            parent[i] --;
        }

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

        // Queries
        for(ll i = 0; i < q; i++){
            ll node, k;
            cin >> node >> k;
            node --;
            
            for(ll j = 0; j < LOG; j++){
                if(k & (1 << j)) {
                    node = up[node][j];

                    if(node == -1) break;
                }
            }

            cout << (node == -1 ? -1 : node + 1) << endl;
        }
    };

    solve();

    return 0;
}
