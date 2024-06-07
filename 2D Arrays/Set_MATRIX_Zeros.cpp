#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        //creating a vector of type bool to store the indexes of zeros.
        vector<bool>set_rows(rows,false);
        vector<bool>set_cols(cols,false);
        //storing the index.
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    set_rows[i] = true;
                    set_cols[j] = true;
                }
            }
        }
        //doing the operation;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(set_rows[i] || set_cols[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};