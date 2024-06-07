//! what is the K sorted array ==> 
    //? Every element present at the index i is either less than or equal to [k- 1] position away from it's correct position in either left or right direction.

    //* For Example: [10, 12, 15, 6, 9] is a valid k sorted array beacuse after sorting it in decreasing order [15, 12, 10, 9, 6] while the array [10, 12, 6, 15, 9] is not a valid k - sorted array.

#include<bits/stdc++.h>
using namespace std;

void kSortedArray(int input[], int n, int k){
    // first element will be in the range of index 0 to (k - 1), and we have to determine the maximum hence lets create a max heap
    priority_queue<int> pq;
    for(int i = 0; i < k; i++){
        pq.push(input[i]);
    }
    int j = 0;
    for(int i = k; i < n; i++){
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);  //* now second element will be from index 0 to 3 at max and so on.
        j++;
    }

    while(!pq.empty()){
        input[j] = pq.top();
        pq.pop();
        j++;
    }
    return;
}

int main(){
    
    int input[5] = {10, 12, 15, 6, 9};

    kSortedArray(input, 5, 3);

    for(int i = 0; i < 5; i++){
        cout << input[i] << " ";
    }

    return 0;
}