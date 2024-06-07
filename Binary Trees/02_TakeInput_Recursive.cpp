#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* takeInput(void){
    int rootData;
    cout << "Enter the data: ";
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

void printBinaryTree(BinaryTreeNode<int>* root){
    if(root != NULL){
        return;
    }
    cout << root->data <<": ";
    if(root->left != NULL){
        cout << "L = "<< root->left->data<<", ";
    }
    if(root->right != NULL){
        cout << "R = "<<root->right->data;
    }
    cout << endl;

    // recursive call
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    printBinaryTree(root);
    return 0;
}