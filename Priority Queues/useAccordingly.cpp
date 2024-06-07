#include<bits/stdc++.h>
using namespace std;

class comparator{
    public:
        bool operator()(const pair<int, int> &p1, pair<int, int> &p2){
            return p1.second < p2.second;
        }
    private:
};

int main(){
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> maxHeap;

    maxHeap.push({1, 5});
    maxHeap.push({2, 3});
    maxHeap.push({3, 7});

    cout << "Max element: " << maxHeap.top().first << endl;

    return 0;
}