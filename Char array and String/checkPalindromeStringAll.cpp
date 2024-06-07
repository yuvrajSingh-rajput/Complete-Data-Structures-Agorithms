#include<iostream>
#include<cctype>
#include<string>
using namespace std;

bool checkPalindrome(string str){
    int left = 0,right = str.length()-1;

    while(left<right){    
        char leftchar = tolower(str[left]);
        char rightchar = tolower(str[right]);
        if((leftchar>='a' && leftchar<='z') || (leftchar>='0' && leftchar<='9')){
            if((rightchar>='a' && rightchar<='z') || (rightchar>='0' && rightchar<='9')){
                if(leftchar!=rightchar){
                    return false;
                }
                else{
                    left++;
                    right--;
                }
                right--;
            }
            left++;
        }
    }
    return true;
}
int main(){
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);
    int palindrome = checkPalindrome(s);
    if(palindrome == 1){
        cout<<"The input string entered by the user is palindrome";
    }
    else{
        cout<<"The input string entered by the user isn't palindrome";
    }
    return 0;
}



//one more solution ;


// bool checkPalindrome(string s){
//     string str="";
//     for(int i=0; i<s.size(); i++){
//         if(s[i]>='0' and s[i]<='9')
//             str.push_back(s[i]);
//         if(s[i]>='a' and s[i]<='z')
//             str.push_back(s[i]);
//         if(s[i]>='A' and s[i]<='Z')
//             str.push_back((s[i]+32));
//     }

//     int i=0, j=str.size()-1;
//     while(i<=j){
//         if(str[i++] != str[j--])
//             return false;
//     }

//     return true;
// }