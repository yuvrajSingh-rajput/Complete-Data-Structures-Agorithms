#include<iostream>
#include<string>
#include<cctype> // tolower and toupper inbuilt function;
using namespace std;
char toLower(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else{
        char lower = ch - 'A' +'a';
        return lower;
    }
}
char toUpper(char ch){
    if(ch>='A' && ch<='Z'){
        return ch;
    }
    else{
        char upper = ch - 'a' + 'A';
        return upper;
    }
}
//It is an efficien code without taking a extra space.
bool chechPalindrome(string s){
    int start = 0;
    int end = s.length()-1;
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        else{
            start++;
            end--;
        }
    }
    return true;
}
int main(){
    string str;
    getline(cin,str);
    cout<<chechPalindrome(str);
    return 0;
}