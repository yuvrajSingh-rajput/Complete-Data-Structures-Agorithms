#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data){
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int>*leftOutput = getRootToNodePath(root->left, data);
    if(leftOutput != NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int>* rightOutput = getRootToNodePath(root->right, data);
    if(rightOutput != NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else{
        return NULL;
    }
}

int main(){
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(4);
    vector<int>* result = getRootToNodePath(root, 8);
    for(int i = 0; i < result->size(); i++){
        cout << result->at(i)<< " " << endl;
    }
    return 0;
}