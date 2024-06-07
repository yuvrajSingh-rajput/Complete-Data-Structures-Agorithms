#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s = "yuvithakuryuvithakuryuvithakur";
    sort(s.begin(),s.end());
    cout<<s<<endl;
    string s2 = "1";
    cout<< stoi(s2)+2;
    return 0;
}