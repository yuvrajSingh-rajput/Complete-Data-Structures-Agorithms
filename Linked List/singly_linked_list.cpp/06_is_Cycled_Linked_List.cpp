#include<iostream>
using namespace std;

//? This algorithm is also Known as { Floyd's Cycle Detection Algorithm };

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

bool hasCycle(Node* head){
    if(head == nullptr || head->next == NULL){
        return false;
    }
    Node *slow = head;
    Node *fast = head;
    while(fast != NULL && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
 
        if(slow == fast){
            return true;
        }
    }
    return false;
}

int main(){
    Node *node1 = new Node(1);
    return 0;
}