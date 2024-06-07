#include<bits/stdc++.h>
using ll = long long;
using namespace std;
 
vector<int> maxOfSubarray(vector<int> nums, int n, int k) {
	deque<int> d;
	for(int i = 0;  i < k; i++){
		while(!d.empty() && d.back() < nums[i]){
			d.pop_back();
		}
		d.push_back(nums[i]);
	}
	int l = 0, m = k;
	vector<int> result;
	result.push_back(d.front());
	while(m < n){
		if(nums[l] == d.front()){
			d.pop_front();
		}
		while(!d.empty() && d.back() < nums[m]){
			d.pop_back();
		}
		d.push_back(nums[m]);
		result.push_back(d.front());
		l++;
		m++;
	}
	return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}