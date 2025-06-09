// Directed Graph:

class DSU {
    vector<int> parent;
public:
    DSU(int n){
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }
    int getParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = getParent(parent[node]);
    }

    bool Union(int u, int v){
        int pu = getParent(u);
        int pv = getParent(v);

        if(pu == pv) return false;
        parent[pv] = pu;
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // To remove an edge: 2 conditions,
        // 1. either two parents
        // 2. or cycle
        int n = edges.size();
        DSU ds(n);

        vector<int> parent(n + 1, 0);
        vector<int> ans1, ans2;
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            if(parent[v] == 0) {
                parent[v] = u;
            }else{
                ans1 = {parent[v], v};   // first edge
                ans2 = edge;             // second edge
                edge[1] = 0;             // temporarily remove 2nd edge for now -> check for cycle
            }
        }

        // Checking for cycle using DSU
        for(auto &edge: edges){
            int u = edge[0], v = edge[1];
            if(v == 0) continue;
            if(!ds.Union(u, v)){
                if(ans1.empty()){ // no two parents - cycle only
                    return edge;
                }
                return ans1;    // both cycle and two parents.
            }
        }

        return ans2;    // no cycle - only two parents;
    }
};
