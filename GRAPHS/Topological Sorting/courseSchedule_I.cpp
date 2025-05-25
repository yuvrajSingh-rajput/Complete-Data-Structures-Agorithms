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


}
