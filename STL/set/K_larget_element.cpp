#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int>K_largestelement(vector<int>& arr,int k){
    vector<int>result;
    set<int>st (arr.begin(),arr.end()); 
    set<int>::reverse_iterator it = st.rbegin();
    if(k<=st.size()){
        for(int i = 0;i<k && it != st.rend();i++){
            result.push_back(*it);
            it++;
        }
    }else{
        for(int i=0;i<st.size() && it!=st.rend();i++){
            result.push_back(*it);
            it++;
        }
    }
    return result;
}

int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    vector<int>v;
    cout<<"Enter the elements in the array: "<<endl;
    for(int i=0;i<size;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int>l = K_largestelement(v,3);
    for(int i=0;i<l.size();i++){
        cout<<l[i]<<" ";
    }
    return 0;
}