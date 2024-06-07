#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m - 1;          // Initialize a pointer for the last element of nums1
        int i2 = n - 1;          // Initialize a pointer for the last element of nums2
        int mergedIndex = m + n - 1;  // Initialize a pointer for the last position in nums1 where we will merge elements

        // Continue merging while there are elements in both nums1 and nums2
        while (i1 >= 0 && i2 >= 0) {
            if (nums1[i1] > nums2[i2]) {
                // If the element in nums1 is greater, copy it to the mergedIndex
                nums1[mergedIndex--] = nums1[i1--];
            } else {
                // If the element in nums2 is greater or equal, copy it to the mergedIndex
                nums1[mergedIndex--] = nums2[i2--];
            }
        }

        // If there are remaining elements in nums2, copy them into nums1
        while (i2 >= 0) {
            nums1[mergedIndex--] = nums2[i2--];
        }
    }
};
