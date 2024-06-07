//* Here we will use the two pointer approach
#include<iostream>
#include<vector>
using namespace std;

vector<int>Union_of_two_arrays(vector<int>& arr1,vector<int>& arr2){
    vector<int>result;
    int i = 0;
    int j = 0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<=arr2[j]){
            if(result.size()==0 || result.back()!=arr1[i]){
                result.push_back(arr1[i]);
            }
            i++;
        }else{
            if(result.size()==0 || result.back()!=arr2[j]){
                result.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<arr1.size()){
        if(result.size()==0||result.back()!=arr1[i]){
            result.push_back(arr1[i]);
        }
        i++;
    }
    while(j<arr2.size()){
        if(result.size()==0||result.back()!=arr2[j]){
            result.push_back(arr2[j]);
        }
        j++;
    }
    return result;
}
int main(){
    vector<int>v1 = {1,1,2,3,4,5};
    vector<int>v2 = {2,3,4,4,5,6};
    vector<int>res = Union_of_two_arrays(v1,v2);
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}