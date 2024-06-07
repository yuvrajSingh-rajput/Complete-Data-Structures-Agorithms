#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

bool isBST_3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }

    if(root->data < min || root->data > max){
        return false;
    }

    bool isLeftOK = isBST_3(root->left, min, root->data - 1);
    bool isRightOK = isBST_3(root->right, root->data, max);
    
    return (isLeftOK && isRightOK);
}

int main(){
    
    return 0;
}