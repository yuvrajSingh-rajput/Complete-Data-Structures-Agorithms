#include<bits/stdc++.h>
using namespace std;

//TODO: A graph is said to be bipartite if every vertex can be colored by using two colors only also every adjacent nodes have different colors.

class Solution {
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& color){
        queue<int> q;
        color[start] = 0;
        q.push(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto adjacentNode: graph[node]){
                if(color[adjacentNode] == -1) 
                    color[adjacentNode] = !color[node], q.push(adjacentNode);
                    
                else if(color[adjacentNode] == color[node]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                bool ans = bfs(i, graph, color);
                if(!ans) return false;
            }
        }
        return true;
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