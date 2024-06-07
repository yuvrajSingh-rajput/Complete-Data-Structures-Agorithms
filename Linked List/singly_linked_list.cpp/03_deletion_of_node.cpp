#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node():data(0),next(nullptr){};
    Node(int val):data(val),next(nullptr){};
    Node(int value,Node* &address):data(value),next(address){};
};

//* Deleting the last Node.
Node* Delete_last_node(Node* &head){
    if(head == nullptr){
        return nullptr;
    }else if(head->next == nullptr){
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while(temp->next != nullptr && temp->next->next != nullptr){    //* By this operation temp will point to second last node.
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head; 
}

//* Constructing the Linked List from an array;
Node* Constructing_the_LL(vector<int> &arr){
    Node* head = nullptr;
    Node *tail = nullptr; 

    for(int i = 0;i<arr.size();i++){
        Node *newNode = new Node(arr.at(i));
        if(head==nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

void printing_LinkedList(Node* &head){
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    vector<int> array = {12,10,8,18,90};
    Node *head = Constructing_the_LL(array);
    cout << "Printing the toatal Linked List: " << endl;
    printing_LinkedList(head);
    cout << "Printing the Linked Listed after Deletion: " << endl;
    Delete_last_node(head);
    printing_LinkedList(head);
    return 0;
}