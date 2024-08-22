#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        //! Priority queue__>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9 + 7);
        dist[S] = 0;
        pq.push({0, S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                
                if(dis + edgeWeight < dist[adjNode]){
                    // push only if this condition will hold.
                    pq.push({dis + edgeWeight, adjNode});

                    //Time complexity: O(E * log(V));
                    dist[adjNode] = dis + edgeWeight;
                }
            }
        }
        return dist;
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
