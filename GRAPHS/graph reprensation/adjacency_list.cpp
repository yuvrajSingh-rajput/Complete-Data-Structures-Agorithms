#include<bits/stdc++.h>
using namespace std;

// if weight is neglected.
vector<vector<int>> adjacency_list(int n, int m, vector<vector<int>>& edges){
    vector<vector<int>> graph(n);
    for(int i = 0; i < n; i++){
        graph[i].push_back(i);
    }
    for(int i = 0; i < m; i++){
        int u = edges[i][0], v = edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}

// if weight is also considered
vector<vector<pair<int, int>>> adjacency_list_with_weight(int n, int m, vector<vector<int>>& edges){
    vector<vector<pair<int, int>>> graph(n);
    for(int i = 0; i < m; i++){
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    return graph;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    return 0;
}