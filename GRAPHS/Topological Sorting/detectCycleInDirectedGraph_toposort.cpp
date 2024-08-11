#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        // let us implement it using topo sorting 
        vector<int> indeg(V, 0);
        for(int i = 0; i < V; i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indeg[i] == 0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it: adj[node]){
                indeg[it] --;
                if(indeg[it] == 0) q.push(it);
            }
        }
        
        return topo.size() != V;
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