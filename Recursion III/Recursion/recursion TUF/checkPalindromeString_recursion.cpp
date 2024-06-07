#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool check_Palindrome_String_Helper(int start,int end, string &s){
    if(start>end){
        return true;
    }
    if(s[start]!=s[end]){
        return false;
    }
    return check_Palindrome_String_Helper(start+1,end-1,s);
}

bool check_Palindrome_String(string &str){
    int s = 0;
    int e = str.length()-1;
    check_Palindrome_String_Helper(s,e,str);
}
int main(){
    string s;
    getline(cin,s);
    if(check_Palindrome_String(s)){
        cout<<"Input string is palindrome!"<<endl;
    }else{
        cout<<"Input string is not palindrome!"<<endl;
    }
    return 0;
}