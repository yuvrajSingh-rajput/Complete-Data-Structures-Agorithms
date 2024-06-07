#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

void allRootToLeafHelper(BinaryTreeNode<int>* root, vector<string>& result, string path = "") {
    if (root == nullptr) {
        return;
    }
    
    // Append the current node's data to the path
    path = path + to_string(root->data);

    // If it's a leaf node, push the path into the result vector
    if (root->left == nullptr && root->right == nullptr) {
        result.push_back(path);
        return;
    }

    // Recursively call for left and right subtrees
    allRootToLeafHelper(root->left, result, path + " ");
    allRootToLeafHelper(root->right, result, path +" ");
}

vector<string> allRootToLeaf(BinaryTreeNode<int>* root) {
    vector<string> result;
    allRootToLeafHelper(root, result);
    return result;
}


int main(){
    
    return 0;
}