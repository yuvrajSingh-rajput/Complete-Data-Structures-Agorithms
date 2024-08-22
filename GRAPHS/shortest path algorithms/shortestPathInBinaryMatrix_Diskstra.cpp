#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({1, {0, 0}});  // Distance starts at 1, since we start at the first cell

        vector<vector<int>> dist(n, vector<int>(n, 1e9 + 7));
        dist[0][0] = 1;

        vector<pair<int, int>> directions = {{-1, 1}, {-1, 0}, {0, 1}, {1, -1}, {1, 0}, {-1, -1}, {0, -1}, {1, 1}, {1, 1}};

        while (!pq.empty()) {
            int dis = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == n - 1 && y == n - 1) return dis;  // Reached the bottom-right corner

            for (int i = 0; i < directions.size(); i++) {
                int xc = x + directions[i].first;
                int yc = y + directions[i].second;

                if (xc < n && xc >= 0 && yc < n && yc >= 0 && grid[xc][yc] == 0 && dis + 1 < dist[xc][yc]) {
                    dist[xc][yc] = dis + 1;
                    pq.push({dis + 1, {xc, yc}});
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