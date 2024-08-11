#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];

        // Create the adjacency list
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];

            int len = min(s1.length(), s2.length());
            for (int j = 0; j < len; j++)
            {
                if (s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }

        // Perform topological sort using Kahn's algorithm
        vector<int> indegree(K, 0);
        for (int i = 0; i < K; i++)
        {
            for (auto it : adj[i])
                indegree[it]++;
        }

        queue<int> q;
        for (int i = 0; i < K; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        string result = "";
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            result.push_back(node + 'a'); // Convert the index back to the character

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        // If the result size doesn't match K, there's an issue with the input (like a cycle)
        if (result.size() != K)
            return "";

        return result;
    }
};

signed main(int argc, char *argv[])
{
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
    auto duration = chrono::duration_cast<chrono::milliseconds>(_clock_end - _clock_start).count();
    cerr << "Execution time: " << duration << " ms." << endl;
#endif

    return 0;
}