#include<bits/stdc++.h>
using namespace std;

class comparePairs {
public:
    bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) {
        if(p1.second != p2.second){
            return p1.second < p2.second;
        }else{
            return p1.first > p2.first;
        }
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for(int i = 0; i < words.size(); i++){
            mpp[words[i]]++;
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>, comparePairs> maxHeap;
        for(auto &it : mpp){
            maxHeap.push({it.first, it.second});
        }
        vector<string> result;
        for(int i = 0; i < k; i++){
            result.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return result;
    }
};

int main(){
    
    return 0;
}


//! Problem statement ==>
    //?Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.