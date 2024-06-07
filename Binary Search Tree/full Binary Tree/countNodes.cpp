#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

int countNodes(BinaryTreeNode<int> *root) {
    if (root == nullptr)
        return 0;

    int leftHeight = 0, rightHeight = 0;
    BinaryTreeNode<int> *leftNode = root, *rightNode = root;

    // Calculate height of left subtree
    while (leftNode != nullptr) {
        leftHeight++;
        leftNode = leftNode->left;
    }

    // Calculate height of right subtree
    while (rightNode != nullptr) {
        rightHeight++;
        rightNode = rightNode->right;
    }

    // If left and right heights are same, then the tree is a full binary tree
    if (leftHeight == rightHeight)
        return (1 << leftHeight) - 1; // Formula to calculate nodes in full binary tree: 2^height - 1

    // Otherwise, the tree is not full, and we calculate recursively
    return 1 + countNodes(root->left) + countNodes(root->right);
}


int main(){
    
    return 0;
}