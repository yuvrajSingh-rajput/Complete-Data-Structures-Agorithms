#include<bits/stdc++.h>
using ll = long long;
using namespace std;

//!Brute Force:-> We are checking every possible combination;
/*!
    Problem statement
    Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:

    1.) Subtract 1 from it. (n = n - ­1) ,
    2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
    3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
    Write brute-force recursive solution for this

*/

int countStepsToOne(int n) {
    vector<int> dp(n + 1, INT_MAX); // Initialize DP array with maximum values
    dp[1] = 0; // Base case: 1 requires 0 steps to reduce to 1

    for (int i = 2; i <= n; ++i) {
        // Reduce by 1
        dp[i] = min(dp[i], dp[i - 1] + 1);
        // If divisible by 2, reduce by half
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        // If divisible by 3, reduce by one-third
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    return dp[n]; // Return the minimum steps for n
}

int countMinStepsToOneHelper(int n, int *arr){
	if(n == 1){
		return 0;
	}
	if(arr[n] != -1){
		return arr[n];
	}
	int step1 = countMinStepsToOneHelper(n - 1, arr);
	int step2 = INT_MAX, step3 = INT_MAX;
	if(n % 3 == 0){
		step2 = min(step2, countMinStepsToOneHelper(n/3, arr));
	}
	if(n % 2 == 0){
		step3 = min(step3, countMinStepsToOneHelper(n/2, arr));
	}
	arr[n] = 1 + min(step1, min(step2, step3));

	return arr[n];
}

int countMinStepsToOne(int n){
	int *ans = new int[n + 1];
	for(int i = 0; i < n + 1; i++){
		ans[i] = -1;
	}
	return countMinStepsToOneHelper(n, ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << countStepsToOne(10) << "\n";
    return 0;
}