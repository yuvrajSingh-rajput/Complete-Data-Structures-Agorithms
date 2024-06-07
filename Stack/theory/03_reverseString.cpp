#include<bits/stdc++.h>
using namespace std;

int main(){
    string name = "maR eerhS iaJ";
    stack<char> st;
    for(int i = 0; i < name.length(); i++){
        st.push(name.at(i));
    }
    string ans = "";
    while(!st.empty()){
        char ch = st.top();
        ans.push_back(ch);
        st.pop();
    }
    cout<<ans<<endl;
    return 0;
}