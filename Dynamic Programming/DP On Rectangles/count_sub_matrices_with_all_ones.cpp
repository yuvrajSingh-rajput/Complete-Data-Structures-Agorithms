class Solution {
  // Intuition for a 1D array - extended for generalized 2D array as well.
    int countSubArray(vector<int>& nums){
        int ones = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                ones++;
            }else {
                ans += (ones * (ones + 1)) / 2;
                ones = 0;
            }
        }
        return ans + (ones * (ones + 1)) / 2;
    }
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            vector<int> states(m, 1);
            for(int j = i; j < n; j++){
                for(int k = 0; k < m; k++){
                    states[k] = states[k] & mat[j][k];
                }
                ans += countSubArray(states);
            }
        }
        return ans;
    }
};
