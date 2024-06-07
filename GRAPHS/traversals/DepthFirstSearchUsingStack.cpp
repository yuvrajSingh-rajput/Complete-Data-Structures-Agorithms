#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, int source){
    int n = graph.size();
    vector<int> visited(n, false), result;
    stack<int> st;
    st.push(source);
    while(!st.empty()){
        int vertex = st.top();
        st.pop();
        if(!visited[vertex]){
            result.push_back(vertex);
            visited[vertex] = true;
            
            for(int i = 0; i < graph[vertex].size(); i++){
                int adjacent_vertex = graph[vertex][i];
                if(!visited[adjacent_vertex]){
                    st.push(adjacent_vertex);
                }
            }
        }
    }
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
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
        {2, 3}, // Vertex 1
        {1, 4, 5}, // Vertex 2
        {1}, // Vertex 3
        {2}, // Vertex 4
        {2}  // Vertex 5
    };

    cout << "Depth First Search (DFS) starting from vertex 1: ";
    dfs(graph, 1);
    return 0;
}