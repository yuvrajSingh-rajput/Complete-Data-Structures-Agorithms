#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node():data(0),next(nullptr){};
    Node(int value):data(value),next(nullptr){};
    Node(int data,Node* &next){
        this->data = data;
        this->next = next;
    }
};

Node* middle_of_Node(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next; 
        if(fast->next != nullptr){
            fast = fast->next;
        }
    }
    return slow;
}

void priting_LL_from_middle(Node *middle_Node){
    while(middle_Node != nullptr){
        cout<< middle_Node->data <<" ";
        middle_Node = middle_Node->next;
    }
}

int main(){
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    priting_LL_from_middle(middle_of_Node(head));
    return 0;
}