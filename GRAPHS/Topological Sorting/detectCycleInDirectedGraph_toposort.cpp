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

