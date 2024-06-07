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

void Delete_the_node(Node* &head, int position){
    int length = 0;
    Node *temp = head;
    while(temp!=nullptr){
        length++;
        temp = temp->next;
    }
    temp = head;
    //NOTE: position is not starting as the indexing of array.
    if(head == nullptr){
        cout<<"There is no any element in linked-list!"<<endl;
        return;
    }
    if(position<=0 || position>length){
        cout<<"The position is out of range, Please enter the number in the range of 1 and "<<length<<"!"<<endl;
    }else{
        for(int i = 1;i<position;i++){
            temp = temp->next;
        }
        Node *nextNode = temp->next;
        temp->data = nextNode->data;
        temp->next = nextNode->next;
        nextNode = nullptr;
        delete nextNode;
    }
}

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
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    Node *node8 = new Node(8);
    Node* head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    cout<<"Before the deletion!"<<endl;
    print_the_Linked_list(head);
    Delete_the_node(head,0);
    cout<<"After the deletion!"<<endl;
    print_the_Linked_list(head);
    return 0;
}