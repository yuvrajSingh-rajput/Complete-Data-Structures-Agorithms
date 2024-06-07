#include<iostream>
#include<vector>
using namespace std;

vector<int>Sort012(vector<int>& arr){
    vector<int>v;
    int Zeroscount=0,Onescount=0,Twoscount=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            Zeroscount= Zeroscount+1;
        }
        else if(arr[i]==1){
            Onescount = Onescount+1;
        }
        else{
            Twoscount=Twoscount+1;
        }
    }
    for(int i=0;i<Zeroscount;i++){
        v.push_back(0);
    }
    for(int i=0;i<Onescount;i++){
        v.push_back(1);
    }
    for(int i=0;i<Twoscount;i++){
        v.push_back(2);
    }
    return v;
}
int main(){
    vector<int>arr = {1,2,1,1,2,0,0,2,1,0,0,0,2,1,0,1};
    vector<int>result = Sort012(arr);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}