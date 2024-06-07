#include<iostream>
using namespace std;
int upperBound(int *arr,int n,int ub){
    int s = 0,e = n-1,ans = n;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid]>ub){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}
int main(){
    int arr[10] = {1,2,3,3,4,5,5,7,9,9};
    cout<< upperBound(arr,10,3);
    return 0;
}