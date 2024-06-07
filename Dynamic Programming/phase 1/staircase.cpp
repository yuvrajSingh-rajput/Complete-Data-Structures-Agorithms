#include<bits/stdc++.h>
using ll = long long;
using namespace std;


//!Problem Statement:
/*
    A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.

    Time complexity of your code should be O(n).

    Since the answer can be pretty large soo print the answer with mod(10^9 +7)
*/
const int MOD = 1e9+7;

//* We can implement this problem by two methods: first one is O(1), second one is O(n);
int countSteps1(int n){
    if(n <= 1){
        return 1;
    }
    vector<int> dp(n + 1, -1);
    int  a = 1, b = 1, c = 2;
    for(int i = 0; i  <= n - 3; i++){
        long long d = (a + b + c) % MOD;
        a = b; 
        b = c;
        c = d;
    }
    return c;
}

int countSteps2(int n){
    if(n <= 1){
        return 1;
    }
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < n + 1; i++){
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
    }
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout <<"Number of all possible ways to climb on the stairs: " << countSteps1(10) << endl;
    return 0;
}