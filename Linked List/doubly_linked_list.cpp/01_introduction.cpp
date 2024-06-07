#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *previous;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->previous = nullptr;
        this->next = nullptr;
    }
};

void insert_At_beginning(Node *&head, int d)
{
    Node *newNode = new Node(d);
    if(head == nullptr){
        head = newNode;
        return;
    }
    newNode->next = head;
    head->previous = newNode;
    head = newNode;
}

void insert_At_end(Node *&head, int d)
{
    Node *temp = head;
    Node *node = new Node(d);
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    node->previous = temp;
}

void print_linked_list(Node *&head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    insert_At_beginning(head, 6);
    insert_At_end(head, 7);
    print_linked_list(head);
    return 0;
}
