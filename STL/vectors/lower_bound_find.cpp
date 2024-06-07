#include<bits/stdc++.h>
using namespace std;

int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    vector<int>arr(size);
    cout<<"Enter the elements in the array: "<<endl;
    for(int i = 0;i<arr.size();i++){
        cin>>arr.at(i);
    }
    int target;
    cout<<"Enter the element to be searched in the array: ";
    cin>>target;
    auto it = lower_bound(arr.begin(),arr.end(),target);
    if(it != arr.end() && *it == target){
        cout<<"Yes "<<std::distance(arr.begin(),it) + 1<<endl;
    }else{
        cout<<"No "<<std::distance(arr.begin(),it) + 1<<endl;
    }

    auto ite = std::find(arr.begin(),arr.end(),target);
    if(ite != arr.end()){
        cout<<"Found at min index: "<<std::distance(arr.begin(),ite);
    }else{
        cout<<"Not present in the array!"<<endl;
    }
    return 0;
}