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

void getLargeNodeCountHelper(TreeNode<int>* root, int x, int *count){
    if(root == NULL){
        return;
    }
    int d = root->data;
    for(int i = 0; i < root->children.size(); i++){
        getLargeNodeCountHelper(root->children[i], x, count);
    }
    if(d > x){
        *count += 1;
    }
    return;
}

int getLargeNodeCount(TreeNode<int>* root, int x) {
    int count = 0;
    getLargeNodeCountHelper(root, x, &count);
    return count;
}

//! ===========================================================================================================================
//* This function checks either a node is present is present with data == x; ================ {PROBLEM 2-----------------}
bool isPresent(TreeNode<int>* root, int x) {
    if (root == NULL) {
        return false;
    }

    if (root->data == x) {
        return true;
    }

    for (int i = 0; i < root->children.size(); i++) {
        if (isPresent(root->children[i], x)) {
            return true;  // Return true as soon as the element is found in any child
        }
    }

    return false;  // Return false if the element is not found in any child
}
//! ============================================================================================================================

int main(){
    
    return 0;
}