#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data; Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* reverseRecursivelyMethod1(Node*& head){
    // base case.
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* smallHead = reverseRecursivelyMethod1(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}

void reverseRecursivelyMethod2(Node*& head, Node* curr, Node* prev){
    if(curr == NULL){
        head = prev;
        return;
    }
    Node* forward = curr->next;
    reverseRecursivelyMethod2(head, forward, prev);
    curr->next = prev;
}

int main(){
    Node* head = new Node(3);
    Node* curr = head;
    Node* prev = NULL;
    reverseRecursivelyMethod2(head, curr, prev);
    return 0;
}