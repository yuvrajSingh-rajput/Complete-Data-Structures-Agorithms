#include<bits/stdc++.h>
#include<fstream>
using namespace std;

int reading_from_CSV(string file_name){
    ifstream input_file;
    input_file.open(file_name, ios_base::in|ios_base::binary);
    if(!input_file.is_open()){
        cout<<"couldn't able to open file!"<<endl;
        return 1;
    }
    string data1, data2, data3;
    while(!input_file.eof()){
        getline(input_file, data1, ',');
        getline(input_file, data2, ',');
        getline(input_file, data3, '\n');

        cout<<data1<<" "<<data2<<" "<<data3<<endl;
    }
    input_file.close();
}

int main(){
    reading_from_CSV("data.csv");
    return 0;
}