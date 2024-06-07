#include<iostream>
using namespace std;

//! start giving default values from rightmost argument to the left.

int sum(int arr[],int size,int start_index = 0){
    int s = 0;
    for(int i=start_index;i<size;i++){
        s = s + arr[i];
    }
    return s;
}
int main(){
    int A[4] = {1,2,3,4};
    cout<<sum(A,4,2)<<endl;
    //* Default argument used here which is equal to ZERO;
    cout<<sum(A,4);
    return 0;
}