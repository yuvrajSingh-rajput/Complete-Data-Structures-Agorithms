#include<bits/stdc++.h>
using ll = long long;
using namespace std;

//* Naive recursive approach without memoization
int fibo_1(int n){
    if(n <= 1){
        return n;
    }
    return fibo_1(n - 1) + fibo_1(n - 2);   // Time Complexity: O(2^n)
}

// Helper function for memoized approach
int fibo_2Helper(int n, int *arr){
    if(n <= 1){
        return n;
    }

    // Memoization step: Check if already computed
    if(arr[n] != -1){
        return arr[n];
    }

    // Recursive call with memoization
    int a = fibo_2Helper(n - 1, arr);
    int b = fibo_2Helper(n - 2, arr);

    // Save the computed value for future use
    arr[n] = a + b;

    return arr[n];
}

//* Memoized approach using dynamic programming
int fibo_2(int n){
    // Initialize an array to store computed Fibonacci numbers
    int *arr = new int[n + 1];
    // Initialize the array with -1 to indicate values not computed yet
    for(int i = 0; i < n + 1; i++){
        arr[i] = -1;
    }

    // Call the helper function to compute Fibonacci numbers with memoization
    return fibo_2Helper(n, arr);
}

//*Iterative approach => dynamic programming => bottom-up approach.
int fibo_3(int n){
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i < n + 1; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fibo_2(8); // Output the 5th Fibonacci number computed using memoized approach
    return 0;
}

//! DYNAMIC PROGRAMMING = (RECURSION + MEMOIZATION).
//* [MEMOIZATION]: it is a technique by which we store our future answer in an array for future use.
//example: Suppose we are solving the fibbonacci number problem by using simpke recursion, in which it makes blindly recursive calls for each number which cause an (~2^n) time complexity while by using the dp we can make it in O(n), simply just make an array which stores the answer of those calls which are previouly made by recursion, Basically the reason for that worst time complexity because same calls were repeated for many time uneccesarily 

//* Memoization is the top-bottom approach and it is always be recursive, while dynamic programming is the bottom-up approach and it will be always iteratively;