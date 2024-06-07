#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>&input, int k){

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            pq.push(input[i][j]);
        }
    }
    vector<int> result;
    
    while (!pq.empty()) {

        result.push_back(pq.top());

        pq.pop();

    }
    return result;

}


int main(){
    
    //? SYNTAX:

    priority_queue<int, vector<int>, greater<int>> pq;
    

    return 0;
}