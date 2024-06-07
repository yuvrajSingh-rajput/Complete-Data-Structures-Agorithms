#include<iostream>
#include<vector>
using namespace std;
bool SortedOrNot(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        if(arr[i]<=arr[i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    vector<int> v;
    
    return 0;
}