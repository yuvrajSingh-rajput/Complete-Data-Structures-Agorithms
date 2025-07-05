#include<bits/stdc++.h>
using ll = long long;
using namespace std;

ll countNodes(vector<vector<ll>>& tree, vector<ll>& nodes, ll root, vector<bool>&vis){
    vis[root] = true;
    ll count = 0;
    for(auto child: tree[root]){
        if(!vis[child]) {
            count += 1 + countNodes(tree, nodes, child, vis);
        }
    }
    nodes[root] = count;
    return count;
}

signed main(int argc, char* argv[]) {
    auto solve = [&]() -> void {
        ll n; 
        cin >> n;
        vector<vector<ll>> tree(n + 1);
        for(ll i = 0; i < n - 1; i++){
            ll u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        vector<ll> nodes(n + 1, 0);
        vector<bool> vis(n + 1, false);
        countNodes(tree, nodes, 1, vis);

        vector<ll> ans(n + 1, -1);
        ans[1] = accumulate(nodes.begin(), nodes.end(), 0LL);

        // BFS
        queue<ll> q;
        q.push(1);
        while(!q.empty()){
            ll parent = q.front();
            q.pop();
            for(auto child: tree[parent]){
                if(ans[child] == -1){
                    ll inc = nodes[parent] - nodes[child];
                    ll dec = nodes[child] + 1;

                    ans[child] = ans[parent] + inc - dec + (nodes[1] - nodes[parent]);

                    q.push(child);
                }
            }
        }

        for(ll i = 1; i <= n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    };

    solve();

    return 0;
}
