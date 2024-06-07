#include<bits/stdc++.h>
using namespace std;

void powerSet(int index, vector<vector<int>>& result, vector<int> output, vector<int>& arr){
    if(index >= arr.size()){
        result.push_back(output);
        return;
    }
    // condition of take 
    output.push_back(arr[index]);
    powerSet(index + 1, result, output, arr);

    // condition not to take 
    output.pop_back();
    powerSet(index + 1, result, output, arr);
}

int main(){
    vector<int> arr = {3, 1, 8, 9};
    int index = 0;
    vector<int> output;
    vector<vector<int>> result;
    powerSet(index, result, output, arr);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}