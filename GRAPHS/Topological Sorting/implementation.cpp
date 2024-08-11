#include<bits/stdc++.h>
using namespace std;

class Solution{
    private: 
    void dfs(int node, vector<bool>& vis, vector<int> adj[], stack<int>& st){
        vis[node] = true;
        for(auto adjacentNode: adj[node]){
            if(!vis[adjacentNode]){
                dfs(adjacentNode, vis, adj, st);
            }
        }
        st.push(node);
    }
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<bool> vis(V, false);
	    stack<int> st;
	    
	    for(int i = 0; i < V; i++){
	        if(!vis[i]){
	            dfs(i, vis, adj, st);
	        }
	    }
	    vector<int> res;
	    while(!st.empty()){
	        res.push_back(st.top());
	        st.pop();
	    }
	    return res;
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
