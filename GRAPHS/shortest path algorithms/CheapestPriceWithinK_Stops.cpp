#include<bits/stdc++.h>
using namespace std;

//Method 1: Normal BFS approach->
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
           adj[it[0]].push_back({it[1],it[2]});

        }
        
        vector<int>price(n,INT_MAX);
        price[src]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stop=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
           
            if(stop>k){
               continue; 
            }
             
            for(auto it:adj[node]){
             
              if(stop<=k&&cost+it.second<price[it.first]){
                 price[it.first]=cost+it.second;
                  q.push({stop+1,{it.first,cost+it.second}});
              }
            }
        }
        if(price[dst]==INT_MAX)return -1;
        return price[dst];
    }
};

//Method 2: Dynamic Programming Approach->
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0], v = flights[i][1], price = flights[i][2];
            graph[u].push_back({v, price});
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        // {price, node, stops};
        pq.push({0, {src, 0}});
        
        // Use a vector of vectors to store the minimum price to reach each node with a certain number of stops
        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));
        dist[src][0] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int price = it.first, node = it.second.first, stops = it.second.second;
            
            // If destination is reached, return the price
            if (node == dst) return price;

            if (stops > k) continue;

            for(auto &next: graph[node]){
                int nextNode = next.first;
                int nextPrice = next.second;
                
                if(price + nextPrice < dist[nextNode][stops + 1]){
                    dist[nextNode][stops + 1] = price + nextPrice;
                    pq.push({price + nextPrice, {nextNode, stops + 1}});
                }
            }
        }

        return -1;
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
