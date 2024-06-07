#include<iostream>
using namespace std;

int firstOccurrence(int arr[],int n,int key){
    int start = 0, end = n-1, mid, index=0;
    mid = start + (end - start)/2;
    while(start<=end){
        if(arr[mid]==key){
            index=mid;
            end = mid - 1;
        }
        else if(arr[mid]>key){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    if(index!=0){
        cout<<"The first index of the searched key is "<<index<<endl;
    }
    else{
        cout<<"The key you searched is not present"<<endl;
    }
}
int lastOccurrence(int arr[],int n,int key){
    int start = 0, end = n-1, mid, index=0;
    mid = start + (end - start)/2;
    while(start<=end){
        if(arr[mid]==key){
            index = mid;
            start = mid+1;
        }
        else if(arr[mid]>key){
            end = mid-1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    if(index!=0){
        cout<<"The last index of the searched key is "<<index<<endl;
    }
    else{
        cout<<"The key you searched is not present"<<endl;
    }
}
int main(){
    int arr[7]={2,4,10,10,10,11,20};
    firstOccurrence(arr,7,10);
    lastOccurrence(arr,7,10);
    return 0;
}