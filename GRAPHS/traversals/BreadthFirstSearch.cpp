#include<bits/stdc++.h>
using namespace std;

void bfsTraversal(vector<vector<int>>& graph, int source){
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        if(!visited[vertex]){
            cout << vertex << " ";
            visited[vertex] = true;

            for(int i = 0; i < graph[vertex].size(); i++){
                int adjacent_vertex = graph[vertex][i];

                if(!visited[adjacent_vertex]){
                    q.push(adjacent_vertex);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    vector<vector<int>> graph = {
        {}, // Vertex 0
        {2, 3, 13}, // Vertex 1
        {5}, // Vertex 2
        {}, // Vertex 3
        {}, // Vertex 4
        {6, 7, 8}, // Vertex 5
        {},  // Vertex 6
        {},  // Vertex 7
        {12},  // Vertex 8
        {},  // Vertex 9
        {},  // Vertex 10
        {},  // Vertex 11
        {},  // Vertex 12
        {}  // Vertex 13
    };

    cout << "Breadth First Search (BFS) starting from vertex 1: ";
    bfsTraversal(graph, 1); // Perform BFS starting from vertex 1
    cout << endl;
    return 0;
}