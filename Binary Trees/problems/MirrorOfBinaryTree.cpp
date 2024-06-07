#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(root == NULL){
		return;
	}
	BinaryTreeNode<int>* leftTemp = root->left;
	root->left = root->right;
	root->right = leftTemp;
	mirrorBinaryTree(root->left);
	mirrorBinaryTree(root->right);
	return;
}

int main(){
    
    return 0;
}