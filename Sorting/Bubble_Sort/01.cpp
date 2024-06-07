#include<bits/stdc++.h>
using namespace std;

void bubbuleSort(vector<int>& nums){
    for(int i = 1; i < nums.size(); i++){
        // pushing the greatest element to it's right place.
        for(int j = 0; j < nums.size() - i; j ++){
            if(nums[i] > nums[j + 1]){
                swap(nums[j], nums[j+1]);
            }
        }
    }
}

void printArray(vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {3, 1, -2, 90, 45, 11};
    printArray(arr);
    bubbuleSort(arr);
    printArray(arr);
    return 0;
}