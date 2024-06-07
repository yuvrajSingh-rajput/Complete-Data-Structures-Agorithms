#include<bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();

void dijkstraAlgorithm(vector<vector<pair<int, int>>>& graph, int source){
    int n = graph.size();
    vector<int> dist(n, INF);
    dist[source] = 0;
    vector<bool> vis(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, source});
    while(!minHeap.empty()){
        int u = minHeap.top().second;
        minHeap.pop();

        if(vis[u])  continue;

        vis[u] = true;

        for(auto &edge : graph[u]){
            int v = edge.first;
            int weight = edge.second;

            if(!vis[v] && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                minHeap.push({dist[v], v});
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

    // adjacency matrix
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<vector<pair<int, int>>> graph(n);
    cout << "Enter the number of edges: ";
    cin >> m;
    // directed graph;
    cout << "Enter the data of edges as: (u, v, wt): \n";
    for(int i = 0; i < m; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back(make_pair(v, wt));
    }
    
    return 0;
}