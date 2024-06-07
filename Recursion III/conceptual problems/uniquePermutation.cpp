#include <vector>
#include <algorithm> // for sort
using namespace std;

class Solution {
    void subsetsWithDupHelper(int idx, vector<int>& nums, vector<int>& subset, vector<vector<int>>& result) {
        result.push_back(subset);
        for (int i = idx; i < nums.size(); ++i) {
            if (i == idx || nums[i] != nums[i - 1]) { // Avoid duplicates
                subset.push_back(nums[i]);
                subsetsWithDupHelper(i + 1, nums, subset, result);
                subset.pop_back();
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        subsetsWithDupHelper(0, nums, subset, result);
        return result;
    }
};

int main(int argc, char* argv[]){

    return 0;
}