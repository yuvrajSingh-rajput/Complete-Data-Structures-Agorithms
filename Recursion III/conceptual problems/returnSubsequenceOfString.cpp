#include<bits/stdc++.h>
using namespace std;

int subsequences(string& input, vector<string>& result){
    // base case
    if(input.empty()){
        result.push_back("");
        return 1;
    }
    // pehla charecter hatakr rest charecters ke liye call kr do
    string smallString = input.substr(1);
    int smallOutputSize = subsequences(smallString, result);
    for(int i = 0; i < smallOutputSize; i++){
        result.push_back((input[0] + result[i]));
    }
    return 2 * smallOutputSize;
}

int main(){
    string input;
    cin >> input; 
    vector<string> result;
    int size = subsequences(input, result);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}