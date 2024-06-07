#include<iostream>
using namespace std;

bool checkPalindome(int arr[],int size){
    //* Base case.
    if(size==0 || size == 1){
        return true;
    }
    if(arr[0]!=arr[size-1]){
        return false;
    }
    return checkPalindome(arr + 1,size-2);
}

int main(){
    int a[6] = {1,2,2,3,2,1};
    cout<<checkPalindome(a,6)<<endl;
    return 0;
}