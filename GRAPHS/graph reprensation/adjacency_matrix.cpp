#include<bits/stdc++.h>
using namespace std;

//!In this representation memory used is too high!, so we moved on towards adjacency list.

void undirected_weighted_graph(vector<vector<int>>& adjacency_mat, vector<vector<int>>& edges){
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];   // (u)----(v)
        adjacency_mat[u][v] = w;
        adjacency_mat[v][u] = w;
    }
    return;
}

void undirected_graph(vector<vector<int>>& adjacency_mat, vector<vector<int>>& edges){
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0], v = edges[i][1];   // (u)----(v)
        adjacency_mat[u][v] = 1;
        adjacency_mat[v][u] = 1;
    }
    return;
}

void directed_graph(vector<vector<int>>& adjacency_mat, vector<vector<int>>& edges){
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i][0], v = edges[i][1];   // (u)---->(v)
        adjacency_mat[u][v] = 1;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    int v, e;
    cin >> v >> e;
    bool directed = false, weighted = false;
    vector<vector<int>> edges(e, vector<int>(2 + directed + weighted));
    for(int i = 0; i < e; i++){
        for(int j = 0; j < edges.size(); i++){
            cin >> edges[i][j];
        }
    }
    vector<vector<int>> adjacency_matrix(v, vector<int>(v, 0));   // assuming 0-based graph
    if(directed){
        directed_graph(adjacency_matrix, edges);
    }else if(!directed){
        undirected_graph(adjacency_matrix, edges);
    }

    return 0;
}