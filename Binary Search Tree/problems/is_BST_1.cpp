#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

//! THE TIME COMPLEXITY OF THIS CODE IS: o(nlogn);-> we will improve its time complexity in this next session.

int maximum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MIN;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MAX;
    }

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root){
    if(root == NULL){
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool result = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return result;
}

int main(){

    /*
        since once we are traversing the tree for the mininim in left as well as for its to be a BST & same for the right, so can we do it at a single time ? 

        we will see the code of it in the next file.

    */
   
    return 0;
}