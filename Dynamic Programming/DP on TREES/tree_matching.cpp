#include<bits/stdc++.h>
using ll = long long;
#define endl "\n";
using namespace std;

ll max(ll a, ll b) { return (a > b) ? a : b; }

vector<vector<int>> dp;

int tree_matching(vector<vector<int>>& adj, int node, int isIncluded, int par){
    if(dp[node][isIncluded] != -1) {
        return dp[node][isIncluded];
    }

    if(isIncluded){
        int ans = 0;
        for(auto neig: adj[node]){
            if(neig != par){
                ans += tree_matching(adj, neig, 1, node);
            }
        }
        int res = 0;
        for(auto neig: adj[node]){
            if(neig != par){
                res = max(res, ans - dp[neig][1] + 1 + tree_matching(adj, neig, 0, node));
            }
        }
        dp[node][isIncluded] = res;
    }else{
        int ans = 0;
        for(auto neig: adj[node]){
            if(neig != par){
                ans += tree_matching(adj, neig, 1, node);
            }
        }
        dp[node][isIncluded] = ans;
    }

    return dp[node][isIncluded];
}

signed main(int argc, char* argv[]) {
    auto solve = [&]() -> void {
        ll n;
        cin >> n;
        vector<vector<int>> adj(n);
        for(ll i = 0; i < n - 1; i++){
            ll u, v;
            cin >> u >> v;
            u --;
            v --;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dp.clear();
        dp.resize(n + 1, vector<int>(2, -1));
        cout << max(tree_matching(adj, 0, 0, -1), tree_matching(adj, 0, 1, -1)); 
        cout << endl;
    };

    solve();
    return 0;
}
