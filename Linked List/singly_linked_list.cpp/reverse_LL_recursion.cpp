#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node *reverseHelper(Node*& head, Node*& curr, Node*& prev, Node*& forward){
    if(curr == NULL){
        return prev;
    }
    forward = curr->next;
    curr -> next = prev;
    prev = curr;
    curr = forward;
    reverseHelper(head, curr, prev, forward);
}

Node* reverse(Node*& head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    return reverseHelper(head, curr, prev, forward);
}

void printLL(Node*& head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node *node1 = new Node(2);
    Node *node2 = new Node(3);
    Node *node3 = new Node(4);
    Node *node4 = new Node(6);
    Node *node5 = new Node(7);
    Node *node6 = new Node(8);
    Node *node7 = new Node(0);
    Node *node8 = new Node(1);

    Node *head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;

    cout<<"Before reverse operation: "<<endl;
    printLL(head);
    cout<<endl;

    cout<<"After reverese operation: "<<endl;
    Node *newHead = reverse(head);
    printLL(newHead);
    return 0;
}