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

//* visualize this problem-> break it in to sub-trees and find maximum of height of sub-trees, then return with root hence we add 1.
int heightOfN_aryTree(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int maxHeight = 0;
    for(int i = 0; i < root->children.size(); i++){
        maxHeight = max(maxHeight, heightOfN_aryTree(root->children[i]));
    }
    return maxHeight + 1;
}

int main(){
    
    return 0;
}