#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v(6);
    for(int ele: v){
        cin>>ele;
        v.push_back(ele);
    }
    int k,count =0;
    cout<<"Enter the element for comparison: ";
    cin>>k;

    for(int i=0;i<v.size();i++){
        if(v[i] > k){
            count ++;
        }
    }
    cout<<count;
    return 0;
}