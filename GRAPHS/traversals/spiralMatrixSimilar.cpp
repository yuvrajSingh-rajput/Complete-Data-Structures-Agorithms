#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void spiralOrderHelper(int i, int j, vector<vector<int>>& matrix, vector<int>& result, vector<vector<bool>>& vis) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Traverse right
        while (j < n && !vis[i][j]) {
            result.push_back(matrix[i][j]);
            vis[i][j] = true;
            j++;
        }
        j--; // Adjust j

        // Traverse down
        i++;
        while (i < m && !vis[i][j]) {
            result.push_back(matrix[i][j]);
            vis[i][j] = true;
            i++;
        }
        i--; // Adjust i

        // Traverse left
        j--;
        while (j >= 0 && !vis[i][j]) {
            result.push_back(matrix[i][j]);
            vis[i][j] = true;
            j--;
        }
        j++; // Adjust j

        // Traverse up
        i--;
        while (i >= 0 && !vis[i][j]) {
            result.push_back(matrix[i][j]);
            vis[i][j] = true;
            i--;
        }
        i++; // Adjust i
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    spiralOrderHelper(i, j, matrix, result, vis);
                }
            }
        }

        return result;
    }
};


int main(){
    
    return 0;
}