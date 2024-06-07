#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(3);
    st.push(3);
    st.push(3);
    st.push(3);
    st.pop();
    if(st.empty()){
        cout<<"Stack is empty."<<endl;
    }else{
        cout<<"Stack isn't empty"<<endl;
    }
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    for(int i = 0; i < st.size(); i++){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}