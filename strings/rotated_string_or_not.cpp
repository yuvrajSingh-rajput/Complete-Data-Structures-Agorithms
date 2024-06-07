#include<iostream>
#include<string>

class Solution {
public:
    bool rotateString(string s, string goal) {
        string S = s + s;
            if(s.length()!=goal.length()){
                return false;
            }
            else{
                if(S.find(goal)!=string::npos){
            return true;
        }
        return false;
            }
    }
};

using namespace std;

int main(){
    
    return 0;
}
