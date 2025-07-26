class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Concept of longest increasing subsequence printing.
        sort(nums.begin(), nums.end());
        // sorting is necessary to check the solution in one direction for correct result.
        int n = nums.size();
        vector<int> hash(n), len(n, 1);
        iota(hash.begin(), hash.end(), 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && len[i] < 1 + len[j]) {
                    len[i] = 1 + len[j];
                    hash[i] = j;
                }
            }
        }

        int maxi = -1, idx = -1;
        for(int i = 0; i < n; i++){
            if(maxi < len[i]){
                maxi = len[i];
                idx = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[idx]);
        while(hash[idx] != idx){
            idx = hash[idx];
            ans.push_back(nums[idx]);
        }
        reverse(ans.begin(), ans.end());


        return ans;
    }
};
