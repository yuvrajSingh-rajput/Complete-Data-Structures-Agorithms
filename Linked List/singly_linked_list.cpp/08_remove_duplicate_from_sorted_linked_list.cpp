#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node():data(0),next(nullptr){};
    Node(int value):data(value),next(nullptr){};
    Node(int data,Node* &next){
        this->data = data;
        this->next = next; 
    }
};

Node* removeDuplicates(Node* head){
    Node* temp = head;
    while(temp!=nullptr && temp->next != nullptr){
        if(temp->data == temp->next->data){
            Node *nextNode = temp->next;
            temp->next = temp->next->next;
            delete nextNode;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}
//* 1 2 3 3 3 3 4 4 4 5 5 7 -1

void print_the_Linked_list(Node* &head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(3);
    Node *node5 = new Node(3);
    Node *node6 = new Node(3);
    Node *node7 = new Node(4);
    Node *node8 = new Node(4);
    Node *node9 = new Node(4);
    Node *node10 = new Node(5);
    Node *node11 = new Node(5);
    Node *node12 = new Node(7);
    Node *node13 = new Node(-1);
    Node* head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;
    node10->next = node11;
    node11->next = node12;
    node12->next = node13;
    Node *temp = removeDuplicates(head);
    print_the_Linked_list(temp);
    return 0;
}