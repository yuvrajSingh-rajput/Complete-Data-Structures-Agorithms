#include<iostream>
#include<vector>
using namespace std;

int binarySearch_recursiveHelper(int start,int end, vector<int>& arr, int target){
    int mid = (start) + (end-start)/2;
    if(start>end){
        return -1;
    }
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]>target){
        return binarySearch_recursiveHelper(start,mid-1,arr,target);
    }else{
        return binarySearch_recursiveHelper(mid+1,end,arr,target);
    }
}
int binarySearch_recursive(vector<int>&arr,int t){
    int s = 0;
    int e = arr.size()-1;
    binarySearch_recursiveHelper(s,e,arr,t);
}
int main(){
    int size;
    cout<<"Enter the size: ";
    cin>>size;
    vector<int>v(size);
    for(int i=0;i<size;i++){
        cin>>v[i];
    }
    cout<<"Element found at index: "<<binarySearch_recursive(v,7)<<endl;
    return 0;
}