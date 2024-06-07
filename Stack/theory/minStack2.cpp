#include<bits/stdc++.h>
using namespace std;

class minStack{
    private:
    stack<int> st, mst;
    public:
    minStack(){};
    void Push(int val){
        if(mst.empty() || val <= mst.top()){
            mst.push(val);
        }
        st.push(val);
    }
    void Pop(){
        if(st.top() == mst.top()){
            mst.pop();
        }
        st.pop();
    }
    int Top(){
        return this->st.top();
    }
    int getMin(){
        return this->mst.top();
    }
};

int main(){
    
    return 0;
}