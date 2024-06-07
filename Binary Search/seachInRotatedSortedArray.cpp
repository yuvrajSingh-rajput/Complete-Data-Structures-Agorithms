#include <iostream>
using namespace std;

int search(int* arr, int n, int key) {
    int left = 0;
    int right = n-1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        // Check if the left half is sorted
        else if (arr[left] <= arr[mid]) {
            if (arr[left] <= key && key <= arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } 
        else { // If the right half is sorted
            if (arr[mid] <= key && key <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    // Element not found
    return -1;
}

int main(){
    int arr[9] = {12,13,15,18,2,4,6,7,9};
    cout<<search(arr,9,7);
}