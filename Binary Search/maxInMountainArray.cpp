#include<iostream>
using namespace std;

int maxMountain(int arr[],int n){
    int start = 0, end = n-1, mid;
    mid = start + (end - start)/2;
    while(start<end){
    if(arr[mid]<arr[mid+1]){
        start = mid + 1;
    }
    else if(arr[mid]>arr[mid-1]){
        end = mid - 1;
    }
    else {
        return mid;
    }
    mid = start + (end - start)/2;
    }
}
int main(){
    int arr[7] = {1,5,23,40,65,55,47};
    maxMountain(arr,7);
    return 0;
}