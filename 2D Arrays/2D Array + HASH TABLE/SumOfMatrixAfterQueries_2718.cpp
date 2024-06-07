#include<bits/stdc++.h>
using namespace std;

long long matrixSumQueries(int n, std::vector<std::vector<int>>& queries) {
    std::unordered_map<int, std::unordered_map<int, int>> matrix;
    
    // Process each query
    for(const auto& query : queries) {
        int type = query[0];
        int idx = query[1];
        int val = query[2];
        
        // Update the matrix based on the type of query
        if(type == 0) {
            // Update row
            for(int j = 0; j < n; ++j) {
                matrix[idx][j] = val;
            }
        } else {
            // Update column
            for(int i = 0; i < n; ++i) {
                matrix[i][idx] = val;
            }
        }
    }
    
    // Calculate the sum of all elements in the matrix
    long long sum = 0;
    for(const auto& row : matrix) {
        for(const auto& cell : row.second) {
            sum += cell.second;
        }
    }
    
    return sum;
}

int main(){
    
    return 0;
}