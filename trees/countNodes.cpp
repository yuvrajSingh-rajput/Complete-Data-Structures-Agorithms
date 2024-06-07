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

int getHeight(TreeNode<int>* root) {
    if (root == nullptr) {
        return 0;
    }

    int maxHeight = 0;
    for (TreeNode<int>* child : root->children) {
        int childHeight = getHeight(child);
        maxHeight = max(maxHeight, childHeight);
    }

    return 1 + maxHeight;
}

int sumOfNodes(TreeNode<int>*root){
    int sum = root->data;
    for(int i = 0; i < root->children.size(); i++){
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}

int countNodes(TreeNode<int>* root){
    int ans = 1;    // root-node
    for(int i = 0; i < root->children.size(); i++){
        ans += countNodes(root->children[i]);   // recursively
    }
    return ans;
}

int main(){
    
    return 0;
}