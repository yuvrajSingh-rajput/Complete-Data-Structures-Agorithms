#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<int>*> children;
    TreeNode(int data){
        this->data = data;
    }
};

void MaximumChildSumNodeHelper(TreeNode<int>* root, TreeNode<int>** maxNode, int* maxSum){
    if(root == NULL){
        return;
    }
    
    int nodeSum = root->data;
    for(int i = 0; i < root->children.size(); i++){
        nodeSum += root->children[i]->data;
        MaximumChildSumNodeHelper(root->children[i], maxNode, maxSum);
    }
    
    if(nodeSum > *maxSum){
        *maxSum = nodeSum;
        *maxNode = root;
    }
    return;
}

TreeNode<int>* MaximumChildSumNode(TreeNode<int>* root){
    int maxSum = 0;
    TreeNode<int>* maxNode;
    MaximumChildSumNodeHelper(root, &maxNode, &maxSum);     //* Passed by reference.
    return maxNode;
}

int main(){
    
    return 0;
}