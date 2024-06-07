#include<iostream>
using namespace std;

int lastIndex(int input[],int size,int target){
    //Base case:
    if(size==0){
        return -1;
    }
    if(input[size-1]==target){
        return size-1;
    }else{
        return lastIndex(input,size-1,target);
    }
}

int main(){
    int arr[7] = {1,2,3,4,5,3,7};
    cout<<lastIndex(arr,7,3)<<endl;
    return 0;
}