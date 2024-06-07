#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* buildBST_Helper(vector<int>& nums, int start, int end){

    if(start > end){
        return NULL;
    }

    int mid = start + (end - start)/2;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(nums[mid]);

    root -> left = buildBST_Helper(nums, start, mid - 1);
    root -> right = buildBST_Helper(nums, mid + 1, end);

    return root;

}

BinaryTreeNode<int>* buildBST(vector<int>& arr){
    if(arr.empty()){
        return NULL;
    }
    return buildBST_Helper(arr, 0, arr.size()-1);
}


int main(){
    
    return 0;
}