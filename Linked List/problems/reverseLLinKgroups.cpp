#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void triangularSum(vector<int>& nums) {
        // Check if the input vector is empty

        // Create a 2D vector with the first row being the input vector
        vector<vector<int>> result;
        result.push_back(nums);

        int n = nums.size();

        // Iterate from the second row to the second-to-last row
        for (int i = 1; i < n; i++) {
            vector<int> row;

            // Iterate through the elements of the previous row to calculate the current row
            for (int j = 0; j < result[i - 1].size() - 1; j++) {
                int k = result[i - 1][j] + result[i - 1][j + 1];
                row.push_back(k % 10);
            }

            // Add the current row to the result
            result.push_back(row);
        }

        // Sum the elements of the last row
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < result[i].size(); j++){
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main(){
    vector<int> inp = {1,2,3,4,5};
    Solution s;
    s.triangularSum(inp);
    return 0;
}