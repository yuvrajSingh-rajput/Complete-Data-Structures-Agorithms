#include<iostream>
using namespace std;

string countandSay(int n){
    if(n==1){
        return "1";
    }
    string s = "1";
    string result = "";
    for(int i=1;i<n;i++){
        result = "";
        int count = 1;
        for(int j = 0;j<s.size();j++){
            if(j+1<s.size() && s[j] == s[j+1]){
                count++;
            }
            else{
                result = result + to_string(count) + s[j];
                count = 1;
            }
        }
        s = result;
    }
    return s;
}
int main(){
    cout<<countandSay(6)<<endl;
    return 0;
}