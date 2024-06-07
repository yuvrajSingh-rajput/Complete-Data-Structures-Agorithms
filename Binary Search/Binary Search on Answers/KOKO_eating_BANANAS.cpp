#include<bits/stdc++.h>
using namespace std;

int totalHours(vector<int>& arr, int mid, int hour){
    int total = 0;
    for(int i = 0; i < arr.size(); i++){
        total += (arr[i]/mid + (arr[i] % mid != 0));
        if(total > hour) break;
    }
    return total;
}

int minEatingSpeed(vector<int>& piles, int hour) {
    int ans = INT_MAX;
    int low = 1, high = *max_element(piles.begin(), piles.end());
    while(low <= high){
        int mid = low + (high - low)/2;
        int k = totalHours(piles, mid, hour);
        if(k <= hour){
            ans = mid; 
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {3, 6, 7, 11};
    cout << minEatingSpeed(arr, 8) << endl;
    return 0;
}