#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int>Union_of_two(vector<int>& arr1,vector<int>& arr2){
    vector<int>result;
    set<int> st(arr1.begin(),arr1.end());
    for(int i=0;i<arr2.size();i++){
        st.insert(arr2[i]);
    }
    for(set<int>::iterator it = st.begin();it!=st.end();it++){
        result.push_back(*it);
    }
    return result;
}
int main(){
    vector<int>v1 = {1,1,2,3,4,5};
    vector<int>v2 = {2,3,4,4,5,6};
    vector<int>res = Union_of_two(v1,v2);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}