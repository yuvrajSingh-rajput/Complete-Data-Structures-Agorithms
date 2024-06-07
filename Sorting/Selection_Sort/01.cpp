#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& nums){
    for(int i = 0; i < nums.size() - 1; i++){
        // to find the minimum index for swapping.
        int minIndex = i;
        for(int j = i; j < nums.size(); j++){
            if(nums[minIndex] > nums[j]){
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
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
    selectionSort(arr);
    printArray(arr);
    return 0;
}