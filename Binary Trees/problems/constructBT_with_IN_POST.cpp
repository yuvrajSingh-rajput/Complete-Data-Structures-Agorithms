#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* constructBinaryTree(vector<int>& inOrder, vector<int>& postOrder){
    
}

void printBinaryTreeInPostOrder(BinaryTreeNode<int>* root){
    printBinaryTreeInPostOrder(root->left);
    printBinaryTreeInPostOrder(root->right);
    cout << root->data << " ";
}

int main(){
        
    return 0;
}