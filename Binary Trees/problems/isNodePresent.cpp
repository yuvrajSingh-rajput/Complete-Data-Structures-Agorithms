#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    if(isNodePresent(root->left, x)){
        return true;
    }
    if(isNodePresent(root->right, x)){
        return true;
    }
    return false;
}

int main(){
    
    return 0;
}