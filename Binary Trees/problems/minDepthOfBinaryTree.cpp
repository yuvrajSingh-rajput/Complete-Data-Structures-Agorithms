#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

int minDepth(BinaryTreeNode<int>* root){
    if (root == nullptr) {
        return 0;
    }
    
    // If one of the subtrees is empty, consider the depth of the other subtree.
    if (root->left == nullptr) {
        return minDepth(root->right) + 1;
    }
    if (root->right == nullptr) {
        return minDepth(root->left) + 1;
    }
    
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    return min(leftDepth, rightDepth) + 1;
}


int main(){
    
    return 0;
}