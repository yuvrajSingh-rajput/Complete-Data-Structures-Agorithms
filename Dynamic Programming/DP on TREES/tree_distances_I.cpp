#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using ll = long long;
const long long mod = 1e9+7;
#define endl "\n";
using namespace __gnu_pbds;
using namespace std;

ll max(ll a, ll b) { return (a > b) ? a : b; }
ll min(ll a, ll b) { return (a < b) ? a : b; }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a * 1LL * b) / gcd(a, b); }

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 0);
    }

    int getParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = getParent(parent[node]);
    }

    void Union(int u, int v) {
        int pu = getParent(u);
        int pv = getParent(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};


vector<ll> dist, dist1, dist2;
vector<bool> vis;

void getDistanceFromNode(vector<vector<ll>>& tree, ll node, vector<ll>& dist) {
    vis[node] = true;

    for (auto child : tree[node]) {
        if (!vis[child]) {
            dist[child] = dist[node] + 1;
            getDistanceFromNode(tree, child, dist);
        }
    }
}

signed main(int argc, char* argv[]) {
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

        vis.assign(n + 1, false);
        dist.assign(n + 1, 0);
        getDistanceFromNode(tree, 1, dist);
        
        vis.assign(n + 1, false);
        dist1.assign(n + 1, 0);
        ll maxi = LLONG_MIN, node = -1;
        for(ll i = 1; i <= n; i++){
            if(maxi < dist[i]) {
                maxi = dist[i];
                node = i;
            }
        }
        getDistanceFromNode(tree, node, dist1);

        vis.assign(n + 1, false);
        dist2.assign(n + 1, 0);
        maxi = LLONG_MIN, node = -1;
        for(ll i = 1; i <= n; i++){
            if(maxi < dist1[i]) {
                maxi = dist1[i];
                node = i;
            }
        }
        getDistanceFromNode(tree, node, dist2);

        for(ll i = 1; i <= n; i++){
            cout << max(dist1[i], dist2[i]) << " ";
        }

        cout << endl;
    };

    solve();

    #ifndef YUVRAJ_SINGH_RAJPUT
        auto _clock_end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(_clock_end - _clock_start).count();
        cerr << "Execution time: " << duration << " ms." << endl;
    #endif
    return 0;
}
