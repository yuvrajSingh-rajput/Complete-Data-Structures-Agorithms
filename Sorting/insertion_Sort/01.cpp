#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& nums){
    // comes to left and swap until it can be.
    for(int i = 0; i < nums.size(); i++){
        for(int j = i; j >= 0; j--){
            if(j - 1 < nums.size() && nums[j] < nums[j - 1]){
                swap(nums[j], nums[j-1]);
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
    insertionSort(arr);
    printArray(arr);
    return 0;
}