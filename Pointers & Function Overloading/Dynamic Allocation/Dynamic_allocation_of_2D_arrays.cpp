#include<iostream>
using namespace std;

int main(){
    int row, col;
    cin>>row>>col;
    int **matrix = new int*[row];
    for(int i=0;i<row;i++){
        matrix[i] = new int[col];
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=i+1;j<col;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<row;i++){
        delete [] matrix[i];
    }
    delete []matrix;
    return 0;
}