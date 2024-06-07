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

// method 1;
void printTree(TreeNode<int>* root){

    if(root == NULL){
        return;     //* Edge case.
    }

    cout << root->data << " ";
    for(int i = 0; i < root->children.size(); i++){
        printTree(root->children[i]);   //* Recursion
    }
}

// method 2;
void printTreeMoreOptimally(TreeNode<int>* root){

    if(root == NULL){
        return;     //* Edge case not the base case.
    }

    cout << root->data << ": ";
    for(int i = 0; i < root->children.size(); i++){
        if(i < root->children.size() - 1){
            cout<< root->children[i]->data << ", ";
        }else{
            cout << root->children[i]->data;
        }
    }
    cout << endl;

    for(int i = 0; i < root->children.size(); i++){
        printTreeMoreOptimally(root->children[i]);
    }
}

//! These are the generic trees, so we don't require any of the base case.

void deleteTree(TreeNode<int>* root){
    for(int i = 0; i < root->children.size(); i++){
        delete root->children[i];
    }
    delete root;
}


int main(){
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* child1 = new TreeNode<int>(2);
    TreeNode<int>* child2 = new TreeNode<int>(3);
    root->children.push_back(child1);
    root->children.push_back(child2);
    printTreeMoreOptimally(root);

    deleteTree(root);
    return 0;
}