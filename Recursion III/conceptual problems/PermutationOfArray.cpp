#include<bits/stdc++.h>
using namespace std;

//! Method 1-> By inbuilt function
class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>vec;
    do{
        vec.push_back(nums);
    }   while(next_permutation(nums.begin(),nums.end()));
    return vec;
    }
};

//! method 2-> By recursion 
class Solution2 {
    int permutations(const vector<int>& nums, vector<vector<int>>& result) {
        if (nums.size() == 0) {
            result.push_back({});
            return 1;
        }
        if (nums.size() == 1) {
            result.push_back(nums);
            return 1;
        }
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> smallerArray;
            for (int j = 0; j < i; j++) {
                smallerArray.push_back(nums[j]);
            }
            for (int j = i + 1; j < nums.size(); j++) {
                smallerArray.push_back(nums[j]);
            }
            vector<vector<int>> smallerResult;
            int smallerSize = permutations(smallerArray, smallerResult);
            int app = nums[i];
            for (int l = 0; l < smallerSize; l++) {
                result.push_back({});
                result[k].push_back(app);
                for (int j = 0; j < smallerResult[l].size(); j++) {
                    result[k].push_back(smallerResult[l][j]);
                }
                k++;
            }
        }
        return k;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permutations(nums, result);
        return result;
    }
};

int main(){
    
    return 0;
}