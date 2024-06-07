#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node * &next){
        this->data = data;
        this->next = next;
    }
};

//* This function returns the head.
Node* Construction_of_LL_with_array_1(vector<int> &arr){
    Node *head = NULL;
    Node *tail = NULL;

    for(int i = 0;i<arr.size();i++){
        //Creating a New instance of Node.
        Node *newNode = new Node(arr.at(i));
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

Node* Construction_of_LL_with_array_2(vector<int> &arr){
    Node* head = new Node(arr.at(0));
    Node* temp = head;
    for(int i = 1;i<arr.size();i++){
        Node* newNode = new Node(arr.at(i));
        temp->next = newNode;
        temp = temp->next;
    }
}

void print_LL(Node* &head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp ->next;
    }
}
int main(){
    vector<int>array = {1,3,5,13,33,4,22};
    Node *arrayToLLHead = Construction_of_LL_with_array_1(array);
    print_LL(arrayToLLHead);
    return 0;
}