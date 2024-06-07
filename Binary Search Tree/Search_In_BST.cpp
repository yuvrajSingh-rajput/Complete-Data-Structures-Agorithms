#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
    if (root == NULL) {
        return;
    }

    if (root->data > k2) {
        elementsInRangeK1K2(root->left, k1, k2);
    } else if (root->data < k1) {
        elementsInRangeK1K2(root->right, k1, k2);
    } else {
        // root->data is within the range [k1, k2]
        elementsInRangeK1K2(root->left, k1, k2);
        cout << root->data << " ";
        elementsInRangeK1K2(root->right, k1, k2);
    }
}


bool searchInBST(BinaryTreeNode<int> *root , int k){
    if(root == NULL){
        return false;
    }
    if(root->data == k){
        return true;
    }else if(root->data < k){
        return searchInBST(root->right, k);
    }else{
        return searchInBST(root->left, k);
    }
}

int main(){
    
    return 0;
}