#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n;
    cin >> n;

    int count = 0;
    while (n > 0) {
        int rem = n % 10;
        if (rem == 4 || rem == 7) {
            count++;
        }
        n = n / 10;
    }
    if(count == 4 || count == 7){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }

    return 0;
}
