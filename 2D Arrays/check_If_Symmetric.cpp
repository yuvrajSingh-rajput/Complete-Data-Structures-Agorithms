#include<iostream>
#include <bits/stdc++.h> 
#include<vector>
using namespace std;
bool isMatrixSymmetric(vector<vector<int>> matrix){
    // Write your code here.
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Create a transpose matrix with the dimensions swapped
    vector<vector<int>> transpose(cols, vector<int>(rows));

    // Populate the transpose matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    } 
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(transpose[i][j]!=matrix[i][j]){
                return false;
            }
        }
    }
    return true;
}