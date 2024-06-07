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

//! This can be said as Depth of the node.
void printAtLevelK(TreeNode<int>* root, int k){
    
    // edge case:
    if(root == NULL){
        return;
    }

    // base case:
    if(k == 0){
        cout << root->data << " ";
        return;
    }

    for(int i = 0; i < root->children.size(); i++){
        printAtLevelK(root->children[i], k-1);
    }
    return;
}

//! ======================================== Count leaf Nodes
void getLeafNodeCountHelper(TreeNode<int>* root, int* total){
    if(root == NULL){
        return;
    }
    if(root->children.size() == 0){
        *total += 1;
    }
    for(int i = 0; i < root->children.size(); i++){
        getLeafNodeCountHelper(root->children[i], total);
    }
    return;
}
//! (+)
int getLeafNodeCount(TreeNode<int>* root) {
    int total = 0;
    getLeafNodeCountHelper(root, &total);
    return total;
}


int main(){
    
    return 0;
}