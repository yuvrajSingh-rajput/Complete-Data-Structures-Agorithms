//* In this sorting technique: We compare the two adjacent elements of the given array.
/*
1. In round 1[0,n-2]: First largest element will come at the last.
2. In round 2: we have to apply bubble sort from [0,n-3];
3. repeat(); till round (n-1);
*/
//! USECASE* : We can insert Kth largest element of the array in Kth round.

#include<iostream>
#include<vector>
using namespace std;

void BubbleSort(vector<int>&arr){
    // For number of rounds.
    for(int i=1;i<arr.size();i++){
        // For the adjacent elements.
        for(int j=0;j<arr.size()-i;j++){
            //Comparing two consecutive elements.
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main(){
    vector<int>v = {1,34,2,6,4};
    BubbleSort(v);
    cout<<"The Sorted array is: "<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}