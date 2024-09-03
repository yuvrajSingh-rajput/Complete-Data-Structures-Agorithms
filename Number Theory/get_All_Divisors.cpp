#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to get all divisors of a given number n
vector<int> getDivisors(int n) {
    vector<int> divisors;
    // Iterate from 1 to sqrt(n)
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {  // If i is a divisor of n
            divisors.push_back(i);  // Add i to divisors
            // If n/i is a different divisor, add it as well
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> divisors = getDivisors(n);

    cout << "Divisors of " << n << " are: ";
    for (int divisor : divisors) {
        cout << divisor << " ";
    }
    cout << endl;

    return 0;
}
