#include<bits/stdc++.h>
using ll = long long;
const long double pi=3.141592653589793238462;
const long long mod = 1e9+7;
using namespace std;

void prefixSum(vector<vector<int>>& prefSum, vector<vector<int>>& mat){
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[0].size(); j++){
            prefSum[i + 1][j + 1] = prefSum[i][j] + mat[i][j];
        }
    }
}

int clockMaxSum(vector<vector<int>>& prefSum, vector<vector<int>>& grid){
    int maxSum = INT32_MIN;
    int row = 3;
    while(row < prefSum.size()){
        int col = 3;
        while(col < prefSum[0].size()){
            int sum = prefSum[row][col] - prefSum[row - 3][col] - prefSum[row][col - 3] + prefSum[row - 3][col - 3] - grid[row - 2][col] - grid[row][col - 2];
            maxSum = max(maxSum, sum);
            col++;
        }
        row++;
    }
    return maxSum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int row = 5, col = 7;
    vector<vector<int>> mat(row, vector<int>(col));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> mat[i][j];
        }
    }
    vector<vector<int>> prefSum(row + 1, vector<int>(col + 1, 0));
    prefixSum(prefSum, mat);
    return 0;
}