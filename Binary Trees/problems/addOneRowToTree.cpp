#include<bits/stdc++.h>
#include"BinaryTreeNode.h"
using namespace std;

class Solution {
    BinaryTreeNode<int>* addOneRowHelper(BinaryTreeNode<int>* root, int val, int depth) {
        if (depth == 1) {
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(val);
            newNode->left = root;
            return newNode;
        }
        if (root == nullptr) return nullptr;
        if (depth - 1 == 1) {
            BinaryTreeNode<int>* newNode1 = new BinaryTreeNode<int>(val);
            BinaryTreeNode<int>* newNode2 = new BinaryTreeNode<int>(val);
            newNode1->left = root->left;
            newNode2->right = root->right;
            root->left = newNode1;
            root->right = newNode2;
        } else {
            root->left = addOneRowHelper(root->left, val, depth - 1);
            root->right = addOneRowHelper(root->right, val, depth - 1);
        }
        return root;
    }
public:
    BinaryTreeNode<int>* addOneRow(BinaryTreeNode<int>* root, int val, int depth) {
        return addOneRowHelper(root, val, depth);
    }
};

int main(int *argc, char* argv[]){
    return 0;
}