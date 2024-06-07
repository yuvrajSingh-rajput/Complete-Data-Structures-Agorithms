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

int countMinStepsToOne(int n){
	if(n == 1){
		return 0;
	}
	int op1 = countMinStepsToOne(n - 1);
	int minSteps = op1;

	if(n % 3 == 0){
		int op2 = countMinStepsToOne(n/3);
		if(op2 < minSteps){
			minSteps = op2;
		}
	}
	
	if(n % 2 == 0){
		int op3 = countMinStepsToOne(n / 2);
		if(op3 < minSteps){
			minSteps = op3;
		}
	}

	return 1 + minSteps;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << countMinStepsToOne(10) << "\n";
    return 0;
}