#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

void printBinaryTree(BinaryTreeNode<int>* root){

    // TODO: Unlike generic trees, here we have to right the base case.

    if(root == NULL){
        return;
    }
    cout << root->data <<": ";
    if(root->left != NULL){
        cout << "L = " << root->left->data <<", ";
    }
    if(root->right != NULL){
        cout << "R = " << root->right->data;
    }
    cout << endl;

    //* Recursive call
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

int main(){
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);                 //      1
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);                /*     / \   */ 
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);               //     2   3
    root->left = node1;
    root->right = node2;
    printBinaryTree(root);
    return 0;
}