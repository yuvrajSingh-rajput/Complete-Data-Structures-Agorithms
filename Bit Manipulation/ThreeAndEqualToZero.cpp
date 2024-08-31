// visit the problem on leetcode(HARD): https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int ans = 0, n = nums.size();

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                mpp[nums[i] & nums[j]]++;
            }
        }

        for(int k = 0; k < n; ++k) {
            for(auto& [req, count] : mpp) {
                if((req & nums[k]) == 0) {
                    ans += count;
                }
            }
        }

        return ans;
    }
};


