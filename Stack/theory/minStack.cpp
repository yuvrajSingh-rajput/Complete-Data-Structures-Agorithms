#include<bits/stdc++.h>
using namespace std;

class minStack{
    private:
        stack<int> st;
        int mini;
    public:
    // constructor.
        minStack(){
            this->mini = INT_MAX;
        }
    // pushElement;
        void Push(int num){
            if(num <= this->mini){
                st.push(this->mini); // to keep track of minimum of the stack;
                this->mini = num;
            }
            st.push(num);
        }
    // popElement;
        void Pop(){
            int topElement = st.top();
            st.pop();
            if(topElement == this->mini){
                this->mini = this->st.top();
                st.pop();
            }
        }
    // topelement;
        int Top(){
            return this->st.top();
        }
    // getMin
        int getMin(){
            return this->mini;
        }
    // exit(0)
};

int main(){
    
    return 0;
}