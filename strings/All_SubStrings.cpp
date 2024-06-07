#include <bits/stdc++.h> 
#include <iostream>
#include <cstring>
using namespace std;

void printSubstrings(string input) {
    //Write your code here
    for(int i=0;i<input.length();i++){
        for(int j=i;j<input.length();j++){
            cout<<input.substr(i,j-i+1)<<endl;
        }
    }
}

int main() {
    string input;
    getline(cin, input);
    printSubstrings(input);
    return 0;
}