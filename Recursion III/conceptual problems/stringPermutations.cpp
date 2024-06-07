#include<bits/stdc++.h>
using namespace std;

void permutations1(string &s, vector<string>& output){
    if(s.empty()){
        output.push_back("");
        return;
    }
    if(s.length() == 1){
        output.push_back(s);
        return;
    }
    for(int i = 0; i < s.length(); i++){
        string smallerString = s.substr(0, i) + s.substr(i + 1);
        vector<string> smallerResult;
        permutations1(smallerString, smallerResult);
        for(int j = 0; j < smallerResult.size(); j++){
            output.push_back(s[i] + smallerResult[j]);
        }
    }
}

void permutations2(string &s, vector<string>& output){
    if(s.empty()){
        output.push_back("");
        return;
    }
    if(s.length() == 1){
        output.push_back(s);
        return;
    }
    string smallerString = s.substr(1);
    vector<string> smallerOutput;
    permutations1(smallerString, smallerOutput);
    for(int i = 0; i < smallerOutput.size(); i++){
        for(int j = 0; j <= smallerOutput[i].length(); j++){
            string str = smallerOutput[i].substr(0, j) + s[0] + smallerOutput[i].substr(j);
            output.push_back(str);
        }
    }
}

int main(){
    string input = "abc";
    vector<string> result;
    permutations2(input, result);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}
