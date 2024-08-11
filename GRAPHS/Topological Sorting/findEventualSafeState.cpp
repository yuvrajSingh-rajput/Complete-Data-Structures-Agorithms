#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int v = g.size();
        // reverse the graph.
        vector<int> graph[v];
        for(int i = 0; i < v; i++){
            for(auto it: g[i]) graph[it].push_back(i);
        }
        vector<int> indeg(v, 0);
        for(int i = 0; i < v; i++){
            for(auto it : graph[i]) indeg[it]++;
        }

        queue<int> q;
        for(int i = 0; i < v; i++)
            if(indeg[i] == 0) q.push(i);

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: graph[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }

        sort(topo.begin(), topo.end());
        return topo;
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

    

    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        auto _clock_end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(_clock_end-_clock_start).count();
        cerr << "Execution time: " << duration << " ms." << endl;
    #endif

    return 0;
}