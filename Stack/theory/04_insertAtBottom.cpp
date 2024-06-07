#include<bits/stdc++.h>
using namespace std;

void insertAtBottomHelper(stack<int>& st, int size, int element){
    if(st.empty()){
        st.push(element);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottomHelper(st, size-1, element);
    st.push(top);
}

void insertAtBottom(stack<int>& st, int element){
    int size = st.size();
    insertAtBottomHelper(st, size, element);
}

int main(){
    stack<int> st;
    st.push(7);
    st.push(1);
    st.push(4);
    st.push(5);
    insertAtBottom(st, 9);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}