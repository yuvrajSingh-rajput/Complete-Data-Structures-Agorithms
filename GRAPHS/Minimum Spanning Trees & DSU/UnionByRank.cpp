#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent;
public: 
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUltimateParent(int node){
        if(node == parent[node]) return node;
        
        // Path compression <<<<<<<<<---------->>>>>>>>>>
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v){
        // find ultimate parent of each nodes: 
        int UP_u = findUltimateParent(u);
        int UP_v = findUltimateParent(v);

        if(UP_u == UP_v) return;

        if(rank[UP_u] < rank[UP_v]) parent[UP_u] = UP_v;

        else if(rank[UP_u] > rank[UP_v]) parent[UP_v] = UP_u;

        else {
            parent[UP_v] = UP_u;
            rank[UP_u]++;
        }
    }
};

signed main(int argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        cin.tie(nullptr);
        auto _clock_start = chrono::high_resolution_clock::now();
    #endif

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    // if 3 and 7 same or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        auto _clock_end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(_clock_end-_clock_start).count();
        cerr << "Execution time: " << duration << " ms." << endl;
    #endif

    return 0;
}