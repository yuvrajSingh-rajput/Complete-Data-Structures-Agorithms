#include<iostream>
#include<cctype>
#include<string>
using namespace std;

// user defined function to covert a uppercase charecter to a lowercase charecter.
char Lower_Case(char ch){
    if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
        return ch;
    }
    else{
        char result = ch - 'A' + 'a';
        return result;
    }
}
bool check_ValidChar(char ch){
    if((ch>='a' && ch<='z') || (ch>='0' && ch<='9') || (ch>='A' && ch<='Z')){
        return true;
    }
    return false;
}
int if_Valid_Palindrome(string s1){
    string s2 = "";
    for(int j=0;j<s1.length();j++){
        if(check_ValidChar(s1[j])){
            s2.push_back(s1[j]);
        }
    }
    //making the string LOwercase;
    for(int i=0;i<s2.length();i++){
        s2[i] = tolower(s2[i]);
    }

    // cheking palindrome or not;
    int start =0, end = s2.length()-1;
    while(start<end){
        if(s2[start]!=s2[end]){
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}
int main(){
    string str;
    cout<<"Enter the string as a input: ";
    getline(cin,str);
    int check = if_Valid_Palindrome(str);
    if(check==1){
        cout<<"The entered string is a valid palindrome."<<endl;
    }
    else{
        cout<<"The entered string is not a valid palindrome."<<endl;
    }
    return 0;
}