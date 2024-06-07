#include<bits/stdc++.h>
using namespace std;

bool checkOdd(vector<int>&arr, int l, int r, int k, int n){
    int sum = 0;
    for(int i = 0; i < l; i++){
        sum = sum + arr[i];
    }
    for(int i = l; i <= r; i++){
        sum = sum + k;
    }
    for(int i = r + 1; i <= n; i++){
        sum = sum + arr[i];
    }
    if(sum % 2 == 0){
        return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t --){
        int n, q;
        cin >> n >> q;
        vector<int> arr(n+1);
        arr[0] = 0;
        for(int i = 1; i <= n ; i++){
            cin >> arr[i];
        }
        while(q --){
            int l, r, k;
            cin >> l >> r >> k;
            if(checkOdd(arr, l, r, k, n)){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}