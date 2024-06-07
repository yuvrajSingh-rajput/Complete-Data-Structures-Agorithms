#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

int height(BinaryTreeNode<int>* root) {
    if(root == NULL){
		return 0;
	}
	int maxHeight = 0;
	maxHeight = max(maxHeight, height(root->left));
	maxHeight = max(maxHeight, height(root->right));
	return maxHeight + 1;
}

int main(){
    
    return 0;
}