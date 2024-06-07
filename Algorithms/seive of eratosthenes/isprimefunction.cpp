#include<bits/stdc++.h>
using ll = long long;
const long double pi=3.141592653589793238462;
const long long mod = 1e9+7;
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false; // 1 and numbers less than 1 are not prime

    // Check divisibility up to the square root of n
    int sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN; i++) {
        if (n % i == 0) {
            return false; // n is divisible by i, so it's not prime
        }
    }
    return true; // n is prime
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    
    return 0;
}