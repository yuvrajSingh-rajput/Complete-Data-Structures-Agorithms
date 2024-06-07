#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

//! On taking its mirror image, It must be as it is.

bool isMirror(BinaryTreeNode<int> *leftSubtree, BinaryTreeNode<int> *rightSubtree){
    if (leftSubtree == NULL && rightSubtree == NULL){
        return true;
    }

    if (leftSubtree == NULL || rightSubtree == NULL){
        return false;
    }

    // Check if the values of the current nodes are equal
    // and if the left subtree is a mirror of the right subtree
    return (leftSubtree->data == rightSubtree->data) &&
           isMirror(leftSubtree->left, rightSubtree->right) &&
           isMirror(leftSubtree->right, rightSubtree->left);
}

bool isSymmetric(BinaryTreeNode<int> *root){
    if (root == NULL){
        return true;
    }

    return isMirror(root->left, root->right);
}

int main(){

    return 0;
}