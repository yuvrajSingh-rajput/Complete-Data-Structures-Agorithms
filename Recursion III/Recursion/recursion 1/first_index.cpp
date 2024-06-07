#include<iostream>
using namespace std;

int firstIndex(int arr[],int size,int target){
    if(size==0){
        return -1;
    }
    if(arr[0]==target){
        return 0;
    }
    int k = firstIndex(arr+1,size-1,target);
    if(k==-1){
        return -1;
    }else{
        return k+1;
    }
}

int main(){
    int a[7] = {1,1,1,2,2,2,3};
    cout<<firstIndex(a,7,2)<<endl;
    return 0;
}