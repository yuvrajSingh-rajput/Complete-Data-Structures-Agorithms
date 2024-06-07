#include<bits/stdc++.h>
using ll = long long;
const long double pi=3.141592653589793238462;
const long long mod = 1e9+7;
using namespace std;

int countPrimes(int n){
  vector<int> ans;
  for (int i = 2; i * i <= n; i++){
    if (n % i == 0) {
      ans.push_back(i);
      while (n % i == 0) {
        n = n / i;
      }
    }
  }
  if (n != 1) {
    ans.push_back(n);
  }
  return ans.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    std::cout << countPrimes(36) << "\n";    // [2, 3] == 2;
    return 0;
}