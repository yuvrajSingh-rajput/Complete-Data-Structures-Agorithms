#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        int delx[] = {-1, 0, 1, 0}, dely[] = {0, -1, 0, 1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int diff = it.first, x = it.second.first, y = it.second.second;

            if(x == n - 1 && y == m - 1) return diff;

            for(int i = 0; i < 4; i++){
                int p = x + delx[i], q = y + dely[i];

                if(p >= 0 && p < n && q < m && q >= 0){
                    int newDiff = max(abs(heights[p][q] - heights[x][y]), diff);

                    if(newDiff < dist[p][q]){
                        dist[p][q] = newDiff;
                        pq.push({newDiff, {p, q}});
                    }
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