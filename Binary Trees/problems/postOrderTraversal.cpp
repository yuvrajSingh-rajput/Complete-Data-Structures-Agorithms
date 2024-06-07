#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

void PostOrderTraversal(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data<<" ";
}

int main(){
    
    return 0;
}