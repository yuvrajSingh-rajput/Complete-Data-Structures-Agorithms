#include <iostream>
#include <vector>
using namespace std;

void sieve_of_eratosthenes(int n){
    vector<bool> isPrime(n + 1, true);
    for(int i = 2; i*i <= n; i++){
        if(isPrime[i]){
            for(int j = i*i; j <= n; j += i){ // Incrementing j by i
                isPrime[j] = false; // Marking multiples of i as non-prime
            }
        }
    }
    for(int i = 2; i <= n; i++){
        if(isPrime[i]){
            cout << i << " ";
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Prime numbers up to " << n << " are: ";
    sieve_of_eratosthenes(n);
    return 0;
}
