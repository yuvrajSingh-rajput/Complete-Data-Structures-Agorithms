#include<bits/stdc++.h>
using namespace std;

class comparePairs {
public:
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparePairs> maxHeap;

        for (auto &it : mpp) {
            maxHeap.push({it.first, it.second});
        }
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return result;
    }
};


//! similar problem is on this concept:
    /*
        1. sort charecter by frequency
        2. sort by words
        3. sort K sorted linked list.
        
    */