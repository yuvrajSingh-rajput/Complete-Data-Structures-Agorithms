#include<bits/stdc++.h>
using namespace std;

//!Intiution: we use maxHeap and minHeap to solve the problem 
/*
    1. maxHeap:  It stores the first half element int the strictly decreasing order.
    2. minHeap: It stores the second half of the element in the strictly increasing order.
    3. condition: it can be visualize if and only if data stream is strictly increasing.
*/

class MedianFinder {
    priority_queue<int> maxHeap; // stores the lower half of the elements
    priority_queue<int, vector<int>, greater<int>> minHeap; // stores the upper half of the elements

public:
    MedianFinder() {
        // constructor
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Rebalance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }
};


int main(){
    
    return 0;
}