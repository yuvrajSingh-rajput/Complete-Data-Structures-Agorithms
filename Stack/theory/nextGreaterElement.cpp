#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	vector<int> result(n);
	stack<int> st;
	st.push(-1);
	for(int i = n-1; i >= 0; i--){
		while(!st.empty() && st.top() <= arr[i]){
			st.pop();
		}
		if(st.empty()){
			result[i] = -1;
		}else{
			result[i] = st.top();
		}
		st.push(arr[i]);
	}
	return result;
}

int main(){
    // block of codes -> implementation.
    return 0;
}