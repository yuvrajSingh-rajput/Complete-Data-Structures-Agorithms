#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

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

//* Inserting the node in the Linked list at the Kth position.
void Insert_at_Kth_position(Node* &head, int d,int pos){

    //creating a node object.
    Node* node = new Node(d);

    Node* temp = head;
    //Let us find the size of the linked list.
    int length = 0;
    while(temp!=NULL){
        length ++;
        temp = temp->next; 
    }
    temp = head;
    if(pos<=0){
        insert_at_first_Node(head,d);
    }else if(pos>0 && pos<length){
        int k = pos-1;
        while(--(k)){
            temp = temp->next;
        } 
        node->next = temp->next;
        temp->next = node;
    }else{
        insert_at_last_Node(head,d);
    }
}

void print_linked_List(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node *node1 = new Node(12);
    Node *node2 = new Node(13);
    Node *node3 = new Node(15);
    Node *node4 = new Node(16);
    Node *node5 = new Node(17);

    Node *head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Insert_at_Kth_position(head,11,-2);
    Insert_at_Kth_position(head,10,0);
    Insert_at_Kth_position(head,14,5);
    Insert_at_Kth_position(head,18,10);

    print_linked_List(head);
    return 0;
}