#include<iostream>
using namespace std;
void transpose(int row,int col,int input[][1001]) {
    for(int i=0;i<col;i++){
        for(int j = 0;j<row;j++){
            cout<<input[j][i]<<" ";
        }
        cout<<endl;
    }
}