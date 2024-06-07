#include<bits/stdc++.h>
using namespace std;

unordered_map<char, string> mpp = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
};

void getAllCombinations(string& digits, vector<string>& result, string output, int index){
    if(index >= digits.length()){
        result.push_back(output);
        return;
    }
    string options = mpp[digits[index]];
    for(int i = 0; i < options.length(); i++){
        output.push_back(options[i]);
        getAllCombinations(digits, result, output, index + 1);
        output.pop_back();   //basically we are removing non-required strings while "BACKTRACKING";
    }
}

int main(int argc, char* argv[]){
    string digits = "234", output = "";
    vector<string> result;
    int index = 0;
    getAllCombinations(digits, result, output, index);
    for(auto &it : result){
        cout << it << endl;
    }
    return 0;
}