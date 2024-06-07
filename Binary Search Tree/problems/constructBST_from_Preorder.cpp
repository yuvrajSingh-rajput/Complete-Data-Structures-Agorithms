#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* bstFromPreorderHelper(vector<int>& preorder, int idx, int upperBound){
    if(idx == preorder.size() || preorder[idx] > upperBound){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[idx++]);
    root->left = bstFromPreorderHelper(preorder, idx, root->data);
    root->right = bstFromPreorderHelper(preorder, idx, upperBound);
    return root;
}

BinaryTreeNode<int>* bstFromPreorder(vector<int>& preorder){
    int idx = 0;
    return bstFromPreorderHelper(preorder, idx, INT_MAX);
}

int main(){
    
    return 0;
}