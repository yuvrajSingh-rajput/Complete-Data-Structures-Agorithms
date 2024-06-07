#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    // constructor
    BinaryTreeNode(T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    // destructor
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

void storeIndex(vector<int>& post, unordered_map<int, int>& mpp){
    for(int i = 0; i < post.size(); i++){
        mpp[post.at(i)] = i;
    }
    return;
}

int idx = 0;

BinaryTreeNode<int>* buildTreeHelper(vector<int>& pre, vector<int>& post, int start, int end, unordered_map<int, int>& mpp){
    if(idx == pre.size() || start > end){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(pre[idx++]);
    if(idx >= pre.size() || start == end){
        return root;
    }

    int index = mpp[pre[idx]];

    root->left = buildTreeHelper(pre, post, start, index, mpp);
    root->right = buildTreeHelper(pre, post, index + 1, end - 1, mpp);
    return root;
}

BinaryTreeNode<int>* buildTree(vector<int>& pre, vector<int>& post){
    if(pre.empty()){
        return NULL;
    }
    unordered_map<int, int> mpp;
    storeIndex(post, mpp);
    return buildTreeHelper(pre, post, 0, post.size()-1, mpp);
}

void printBinaryTree_Inorderly(BinaryTreeNode<int>* root){
    if(root == NULL)    return;
    printBinaryTree_Inorderly(root->left);
    cout << root-> data << " ";
    printBinaryTree_Inorderly(root->right);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> preOrder= {8, 2, 7, 10, 4, 3, 9, 12, 14, 9};
    vector<int> postOrder = {10, 7, 3, 9, 4, 2, 9, 14, 12, 8};
    BinaryTreeNode<int>* root = buildTree(preOrder, postOrder);
    printBinaryTree_Inorderly(root);
    return 0;
}