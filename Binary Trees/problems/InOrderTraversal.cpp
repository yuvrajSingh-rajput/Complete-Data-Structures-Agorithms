#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

void InorderTraversal(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    InorderTraversal(root->left);
    cout << root->data<<" ";
    InorderTraversal(root->right);
}

int main(){
    
    return 0;
}