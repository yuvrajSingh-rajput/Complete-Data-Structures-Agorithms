#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create graph first->
        vector<int> adj[numCourses];
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        // implement topological sort->
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            for(auto it: adj[i]) indegree[it]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0) q.push(i);

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        //condition if there is no cycle.
        return topo.size() == numCourses;
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