#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1,3,2,5,9,7};
    stack<int> st;
    st.push(-1);
    vector<int> result(arr.size());
    for(int i = arr.size() - 1; i >= 0; i--){
        while(st.top() >= arr[i]){
            st.pop();
        }
        result[i] = st.top();
        st.push(arr[i]);
    }
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}