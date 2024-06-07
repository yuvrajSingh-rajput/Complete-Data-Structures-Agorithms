#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

//! floor value of an element in BST.
void FloorHelper(BinaryTreeNode<int>* root, int input, int &floorVal){
	if(root == NULL){
		return;
	}

	if(root->data == input){
		floorVal = input;
		return;
	}
	if(root->data > input){
		FloorHelper(root->left, input, floorVal);
	}else if(root->data < input){
		floorVal = max(floorVal, root->data);
		FloorHelper(root->right, input, floorVal);
	}
}
int Floor(BinaryTreeNode<int> *root, int input){
	int floorVal = INT_MIN;
	FloorHelper(root, input, floorVal);
	return floorVal == INT_MIN ? -1 : floorVal;
}


//! ceil value in BST of an element.
void findCeilHelper(BinaryTreeNode<int>* root, int x, int& ceilVal) {
    if (root == NULL) {
        return;
    }

    if (root->data == x) {
        ceilVal = x;
        return;
    }

    if (root->data > x) {
        ceilVal = std::min(ceilVal, root->data);
        findCeilHelper(root->left, x, ceilVal);
    } else if (root->data < x) {
        findCeilHelper(root->right, x, ceilVal);
    }
}
int findCeil(BinaryTreeNode<int>* root, int x) {
    int ceilVal = INT_MAX;  // Initialize with a large value
    findCeilHelper(root, x, ceilVal);
    return (ceilVal == INT_MAX) ? -1 : ceilVal;
}

//! min-value in BST.
int minValue(BinaryTreeNode<int>* root){
    if(root == NULL){
        return -1;
    }

    while(root->left != NULL){
        root = root->left;
    }

    return root->data;
}

int main(){
    
    return 0;
}