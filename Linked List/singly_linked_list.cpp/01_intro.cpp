#include<bits/stdc++.h>
using namespace std;

//A class Which defines a Node or Node object.
class Node{
    public: 
    int data;
    Node *next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//* Inserting a Node at the first.
void insert_at_first_Node(Node* &head, int d){
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

//* Inserting a Node at the last.
void insert_at_last_Node(Node* &head, int d){
    //First let us find the tail First
    Node* temp = head;
    while (temp->next != NULL) {
    temp = temp->next;
    }
    Node *temp1 = new Node(d);
    temp->next = temp1;
}

//* Printing the Linked List.
void print_linked_list(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node *node1 = new Node(10);
    Node *node2 = new Node(19);
    Node *node3 = new Node(23);

    Node *head = node1;
    insert_at_first_Node(head,8);
    node1->next = node2;
    node2->next = node3;
    insert_at_last_Node(head,28);

    print_linked_list(head);
    return 0;
}