#include <iostream>
#include <vector>

using namespace std;

int findPivotIndex(const vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // If the element at mid is greater than the element at mid + 1, we found the pivot index.
        if (nums[mid] > nums[mid + 1]) {
            return mid + 1;
        } else {
            // If the element at mid is greater than the element at right, the pivot index is on the right side.
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                // If the element at mid is less than or equal to the element at right, the pivot index is on the left side.
                right = mid;
            }
        }
    }

    // If the array is not rotated, the pivot index is 0.
    return 0;
}

int main() {
    vector<int> rotatedSortedArray = {4, 5, 6, 7, 0, 1, 2};
    int pivotIndex = findPivotIndex(rotatedSortedArray);
    cout << "The pivot index is: " << pivotIndex << endl;
    return 0;
}

// #include<iostream>
// using namespace std;
// int pivotIndex(int arr[],int n){
//     int start = 0, end = n-1, mid, next, previous;
//     mid = start + (end - start)/2; 
//     while(start<=end){
//         next = (mid + 1)% n;
//         previous = (mid + n -1)% n;
//         if(arr[mid]<=arr[next] && arr[mid]<=arr[previous]){
//             return mid;
//         }
//         else if(arr[start]<arr[mid]){
//             start = mid + 1;
//         }
//         else if(arr[mid]<arr[end]){
//             end = mid - 1;
//         }
//         else{
//             return mid;
//         }
//         mid = start + (end - start)/2;
//     }
// }
// int main(){
//     int arr[8];
//     cout<<"Enter the elements in the array: \n";
//     for(int i = 0;i<8;i++){
//         cin>>arr[i];
//     }
//     cout<<pivotIndex(arr,8);
//     return 0;
// }