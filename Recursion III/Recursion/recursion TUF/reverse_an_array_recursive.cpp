#include<iostream>
#include<vector>
using namespace std;

void reverse_array_recursive_Helper(int start,int end,vector<int>& arr){
    if(start>end){
        return;
    }
    swap(arr[start],arr[end]);
    return reverse_array_recursive_Helper(start+1,end-1,arr);
}
void reverse_array_recursive(vector<int>& arr){
    int s = 0;
    int e = arr.size()-1;
    reverse_array_recursive_Helper(s,e,arr);
}
int main(){
    vector<int>v = {1,2,3,4,5};
    reverse_array_recursive(v);
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}