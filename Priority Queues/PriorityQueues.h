#include<bits/stdc++.h>
using namespace std;

class PriorityQueues{
    vector<int> pq;
    
    public:
    PriorityQueues(){
        //* constructor
    }

    bool isEmpty(){
        return pq.size() == 0;
    }

    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(pq.empty()){
            return 0;
        }
        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while(childIndex > 0){
            int parentIndex = (childIndex - 1)/2;

            if(pq[childIndex] < pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }else{
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin(){
        if(pq.empty()) return 0;
        
        int lastIndex = pq.size() - 1, ans = pq[0];
        pq[0] = pq[lastIndex];

        int parentIndex = 0;
        int childIndex1 = (2 * parentIndex) + 1, childIndex2 = (2 * parentIndex) + 2;

        while(childIndex1 < pq.size()){
            int minIndex = parentIndex;
            
            if(pq[parentIndex] > pq[childIndex1] && childIndex2 < pq.size() && pq[parentIndex] > pq[childIndex2]){
                if(pq[childIndex1] < pq[childIndex2]){
                    minIndex = childIndex1;
                }else{
                    minIndex = childIndex2;
                }
            }else if(pq[parentIndex] > pq[childIndex1]){
                minIndex = childIndex1;
            }else if(childIndex2 < pq.size() && pq[parentIndex] > pq[childIndex2]){
                minIndex = childIndex2;
            }
            if(minIndex == parentIndex){
                break;
            }
            // swapping
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            childIndex1 = (2 * parentIndex) + 1;
            childIndex2 = (2 * parentIndex) + 2;
        }
        return ans;
    }
};

    //! NOTE ==========>
        //? when we call removeMin() until the pq gets empty it prints the elements in sorted fashion, This is also called as Heap sort.