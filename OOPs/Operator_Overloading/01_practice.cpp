#include<bits/stdc++.h>
using namespace std;

class matrix{

    private:
    int row,col;
    vector<vector<int>>mat;

    public:
    matrix(void){}
    matrix(int row, int col){
        this->row = row;
        this->col = col;
        mat.resize(row, vector<int>(col,0));
    }
    friend istream& operator >> (istream & in, matrix& m);
    friend matrix transpose(matrix &);
    friend ostream& operator<<(ostream& out, matrix&);

    matrix operator+(matrix& mat){
        matrix temp(row,col);
        if(this->row == mat.row && this->col == mat.col){
            for(int i = 0;i<this->row;i++){
                for(int j = 0;j<this->col;j++){
                    temp.mat[i][j] = this->mat[i][j] + mat.mat[i][j];
                }
            }
            return temp;
        }else{
            cout<<"Matrix dimensions aren't same, Hence can't added!"<<endl;
            return matrix();
        }
    }

    matrix operator-(matrix& m){
        matrix subs(row, col);
        if(this->mat.size() == m.row && this->mat[0].size() == m.col){
            for(int i = 0; i<this->mat.size(); i++){
                for(int j = 0; j<this->mat[0].size(); j++){
                    subs.mat[i][j] = this->mat[i][j] - m.mat[i][j];
                }
            }
            return subs;
        }else{
            cout<<"Matrix dimension aren't same, Hence can't subtracted!"<<endl;
            return matrix();
        }
    }

    matrix operator* (matrix& m){
        matrix multi(row, m.col);
        if(this->mat[0].size() != m.col){
            cout<<"Dimension Error, Hence they can't multiplied!"<<endl;
            return matrix();
        }else{
            for(int i = 0; i<row; i++){
                for(int j = 0; j<m.col; ++j){
                    for(int k = 0; k<col; k++){
                        multi.mat[i][j] = multi.mat[i][j] + this->mat[i][k] + m.mat[k][j];
                    }
                }
            }
            return multi;
        }
    }
    void display(matrix&);
};

istream& operator>> (istream& in, matrix& m){
    cout<<"Enter the matrix elements: "<<endl;
    for(int i = 0; i<m.row; i++){
        for(int j = 0; j<m.col; j++){
            in>> m.mat[i][j];
        }
    }
}

matrix transpose(matrix &m){
    for(int i = 0;i<m.row;i++){
        for(int j = i+1;j<m.col;j++){
            swap(m.mat[i][j],m.mat[j][i]);
        }
    }
    return m;
}

ostream& operator<<(ostream& out, matrix& m){
    for(int i = 0; i<m.mat.size(); i++){
        for(int j = 0; j<m.mat[0].size(); j++){
            out<< m.mat[i][j] << " ";
        }
        out<<"\n";
    }
    return out;
}

void matrix::display(matrix& m){
    for(int i = 0; i<m.mat.size(); i++){
        for(int j = 0; j<m.mat[0].size(); j++){
            cout<< m.mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    //* Here we can implement all the methods and overloading of the class for a 2-D matrix;
    return 0;
}