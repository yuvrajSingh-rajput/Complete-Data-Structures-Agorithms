#include<vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftsum = 0 , rightsum = 0 , prefix = 0;
        for(int i = 0 ; i < n ; i++){
            prefix += nums[i];// add all element in prefix 
        }
        rightsum  = prefix ; // make rightsum eqaul to prefix sum
        for(int j= 0 ; j<n ; j++){
            leftsum += nums[j]; // add element in leftsum and check if (leftsum==rightsum) at any index before substracting element from rightsum, if find eqaul then return that index 
            if(rightsum == leftsum) return j;
            rightsum -= nums[j];

        }
        return -1;// means not pivot index find 
    }
};