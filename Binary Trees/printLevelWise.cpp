#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

void printLevelWise(BinaryTreeNode<int> *root) {
	if(root == NULL){
		return;
	}
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty()){
		BinaryTreeNode<int>* f = pendingNodes.front();
		pendingNodes.pop();
		cout << f->data<<":";
		if(f->left != NULL){
			cout <<"L:"<< f->left->data<<",";
			pendingNodes.push(f->left);
		}else{
			cout << "L:-1,";
		}
		if(f->right != NULL){
			cout <<"R:"<< f->right->data;
			pendingNodes.push(f->right);
		}else{
			cout <<"R:-1";
		}
		cout << endl;
	}
	return;
}

int main(){
    
    return 0;
}