#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, int source, vector<bool>& visited){
    visited[source] = true;
    cout << source << " ";

    // traverse for its childrens.
    for(int i = 0; i < graph[source].size(); i++){
        int adjacent_vertex = graph[source][i];
        if(!visited[adjacent_vertex]){
            dfs(graph, adjacent_vertex, visited);
        }
    }
}

void dfsTraversal(vector<vector<int>>& graph, int source){
    int n = graph.size();
    vector<bool> visited(n, false);
    
    dfs(graph, source, visited);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    vector<vector<int>> graph = {
        {}, // Vertex 0
        {2, 3}, // Vertex 1
        {1, 4, 5}, // Vertex 2
        {1}, // Vertex 3
        {2}, // Vertex 4
        {2}  // Vertex 5
    };

    cout << "Depth First Search (DFS) starting from vertex 1: ";
    dfsTraversal(graph, 1);
    return 0;
}