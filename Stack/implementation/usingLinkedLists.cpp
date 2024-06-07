#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Node{
    public:
    int data;
    Node* next;
    Node(T data){
        this->data = data;
        this->next = NULL;
    }
};

template<typename T>

class Stack{
    public:
    Node<T> *head;
    int size;
    // Constructor
    Stack(){
        this->head = NULL;
        this->size = 0;
    }
    // to know the size of the stack.
    int getSize(){
        return size;
    }
    // to check whether the stack is empty or not.
    bool isEmpty(){
        return size == 0;
    }
    // PUSH
    void pushElement(int data){
        Node<T> *newNode = new Node<T>(data);
        newNode -> next = head;
        head = newNode;
        this->size++;
    }
    // POP
    T popElement() {
    if (head) {
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }
    return 0; // Return a default value (you may want to handle this differently based on your use case)
}

    // TOP
    T TOP(){
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }
};

int main(){
    Stack<int> st;
    st.pushElement(3);
    st.popElement();
    st.pushElement(33);
    cout << st.getSize() <<"\n";
    cout << st.TOP() <<"\n";
    return 0;
}