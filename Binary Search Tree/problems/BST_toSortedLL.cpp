#include<bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    Node<T>* next;

    Node(T data){
        this->data = data;
        this->next = NULL;
    }
};

void constructLinkedListHelper(BinaryTreeNode<int>* root, Node<int>*& head, Node<int>*&curr){
	if(root == NULL){
		return ;
	}
	constructLinkedListHelper(root->left, head, curr);
	Node<int>* newNode = new Node<int>(root->data);
	if(head == NULL){
		head = newNode;
		curr = head;
	}else{
		curr->next = newNode;
		curr = newNode;
	}
	constructLinkedListHelper(root->right, head, curr);
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	if(root == NULL){
		return NULL;
	}
	Node<int>* head = NULL, *curr = NULL;
	constructLinkedListHelper(root, head, curr);
	return head;
}

int main(){
    
    return 0;
}