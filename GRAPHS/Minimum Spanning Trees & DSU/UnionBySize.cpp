#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> size, parent;
public: 
    DisjointSet(int n){
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUltimateParent(int node){
        if(node == parent[node]) return node;
        
        // Path compression <<<<<<<<<---------->>>>>>>>>>
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v){
        // find ultimate parent of each nodes: 
        int UP_u = findUltimateParent(u);
        int UP_v = findUltimateParent(v);

        if(UP_u == UP_v) return;

        if(size[UP_u] < size[UP_v]) {
            parent[UP_u] = UP_v;
            size[UP_v] += size[UP_u];

        }else {
            parent[UP_v] = UP_u;
            size[UP_u] += size[UP_v];
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
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

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