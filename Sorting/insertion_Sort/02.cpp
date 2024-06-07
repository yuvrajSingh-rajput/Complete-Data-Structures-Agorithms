#include<bits/stdc++.h>
using namespace std;

// recursive approach
void placeAtCorrectPosition(vector<int>& nums, int idx){
    if(idx - 1 < 0){
        return;
    }else if(idx - 1 > 0 && nums[idx] >= nums[idx - 1]){
        return;
    }
    swap(nums[idx], nums[idx - 1]);
    placeAtCorrectPosition(nums, idx - 1);
}

void insertionSortRecursive(vector<int>& nums, int idx){
    if(idx == nums.size()){
        return;
    }
    placeAtCorrectPosition(nums, idx);
    insertionSortRecursive(nums, idx + 1);
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
    insertionSortRecursive(arr, 0);
    printArray(arr);
    return 0;
}