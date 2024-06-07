#include<bits/stdc++.h>
using namespace std;

template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(int data){
        this->data = data;
    }
};

//! RECURSIVE METHOD->>

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if(root == NULL){
        return NULL;
    }
    
    TreeNode<int>* max = root;
    for(int i = 0; i < root->children.size(); i++){
        TreeNode<int>* maxChild = maxDataNode(root->children[i]);
        if(maxChild->data > max->data){
            max = maxChild;
        }
    }
    return max;
}

int main(){
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* child1 = new TreeNode<int>(2);
    TreeNode<int>* child2 = new TreeNode<int>(3);
    root->children.push_back(child1);
    root->children.push_back(child2);
    return 0;
}