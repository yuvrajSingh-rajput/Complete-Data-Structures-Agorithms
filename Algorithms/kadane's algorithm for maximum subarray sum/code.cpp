#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int>& arr){
    int sum = 0, maxi = arr[0];
    for(int i = 0; i < arr.size(); i++){
        sum = sum + arr[i];     // step-1
        maxi = max(maxi, sum);  // step-2
        if(sum < 0){            // step-3
            sum = 0;
        }
    }
    return maxi;
}

int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubarraySum(arr) << endl;
    return 0;
}