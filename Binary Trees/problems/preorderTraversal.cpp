#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* takeInputLevelwise(void){
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* f = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of "<< f->data<<": ";
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>*leftChildNode = new BinaryTreeNode<int>(leftChildData);
            f->left = leftChildNode;
            pendingNodes.push(leftChildNode);
        }

        cout << "Enter right child of "<< f->data<<": ";
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>*rightChildNode = new BinaryTreeNode<int>(rightChildData);
            f->right = rightChildNode;
            pendingNodes.push(rightChildNode);
        }
    }
}

void PrintByPreorderTraversal(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout << root->data <<" ";
    PrintByPreorderTraversal(root->left);
    PrintByPreorderTraversal(root->right);
}

int main(){
    
    return 0;
}