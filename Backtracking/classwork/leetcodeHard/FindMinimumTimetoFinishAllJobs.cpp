#include<bits/stdc++.h>
using ll = long long;
const long double pi=3.141592653589793238462;
const long long mod = 1e9+7;
using namespace std;

ll max(ll a, ll b) { return (a > b) ? a : b;}
ll min(ll a, ll b) { return (a < b) ? a : b;}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) { return (a * 1LL * b) / gcd(a, b);}

//Actual function starts here.
class Solution {
private:
    vector<int> works;
    int ans = INT_MAX;

    void solveBackTrack(int i, vector<int>& jobs, int n, int k) {
        if (i == n) {
            int maxWork = *max_element(works.begin(), works.end());
            ans = min(ans, maxWork);
            return;
        }
        if(*max_element(works.begin(), works.end()) >= ans) return;

        for (int j = 0; j < k; j++) {
            if (j > 0 && works[j] == works[j - 1])
                continue;
            works[j] += jobs[i];
            solveBackTrack(i + 1, jobs, n, k);
            works[j] -= jobs[i];
        }
    }

public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend()); 
        int n = jobs.size();
        if (k == n)
            return jobs[0];

        works.resize(k, 0); 
        solveBackTrack(0, jobs, n, k); 
        return ans;
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

    solve();

    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        auto _clock_end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(_clock_end-_clock_start).count();
        cerr << "Execution time: " << duration << " ms." << endl;
    #endif

    return 0;
}

/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠠⢀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⢀⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⣠⢤⡀⢁⡀⠀⠢⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠶⢶⡖⢺⡇⠀⢀⠀⣹⡇⢸⡇⠀⠀⠀⠘⠧⣨⠇⣘⡃⠀⢣⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣄⠀⣸⡿⢸⡇⠀⠹⣾⣉⢀⣬⣇⠀⠀⠀⠈⠛⣩⠓⠹⠂⠀⠣⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠉⠀⠈⠋⠀⠀⠉⠉⠉⠈⠚⠀⠀⠀⠀⠙⠋⠀⠀⠃⠀⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⡶⢿⣿⣿⣿⣶⣤⡀⠿⠿⠿⠿⢿⣟⡿⡿⠿⠿⠟⠿⠭⠍⠍⡣⠐⠈⠁⠁⠄⡐⠄⠐⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠠⠞⠋⠉⠁⠈⠉⠛⣿⣿⣿⣷⡄⠀⠀⠀⢸⣟⣷⡇⠀⠀⠀⠀⠀⠀⢂⣁⠒⠀⠀⠀⢀⠡⠐⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣿⣿⣿⡀⠀⠀⢸⣿⣿⡇⠀⠀⠀⢀⣀⠄⣇⠒⡄⠄⠠⠀⠂⠄⠡⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣿⣿⣿⣿⠇⠀⠀⢸⣿⣿⡇⠀⠀⣤⣵⡌⠉⠤⢊⠰⠈⠀⠀⡀⢁⣐⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢀⣤⣶⣶⣶⣶⣶⣤⣤⣀⣀⣀⣀⣴⣿⣿⣿⡿⠉⠀⠀⠀⢸⣿⣿⡇⠀⠀⣿⢧⡀⠀⢒⠠⢡⠀⠀⠀⡉⢀⢂⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠈⠁⠀⠀⠈⠙⢿⣿⣿⣿⣿⡿⠿⠿⠟⠛⠉⠀⠀⠀⠀⠀⢸⣿⣿⡇⠀⠀⠻⡚⡵⢀⢪⢐⠢⠀⠀⠀⢈⠁⢢⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣿⣿⣿⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣧⡀⠀⠀⠑⠌⣃⠆⡂⠀⠀⠀⠀⡀⡌⠄⡀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠿⣿⣿⣿⣿⣦⣀⠀⠀⠀⠀⠀⠀⠒⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠂⠈⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠻⣿⣿⣿⣿⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢦⠪⠖⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣷⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢨⣭⡋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⢿⣿⣿⣿⣿⣿⣿⣤⣄⡀⠀⠀⠀⢀⣠⣤⣿⡜⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⠿⣿⣿⣿⣿⣿⣿⣿⣸⣿⣿⠿⡼⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠛⠛⠛⠛⠚⠓⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀

*/
