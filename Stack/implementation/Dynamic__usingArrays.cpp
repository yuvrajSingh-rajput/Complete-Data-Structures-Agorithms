#include<bits/stdc++.h>
using namespace std;

class Stack{
    int capacity;
    int *arr;
    int top;
    public:
    // constructor.
    Stack(){
        this->capacity = 5;
        this->arr = new int[this->capacity];
        this->top = -1;
    }
    // PUSH ====================================
    void PUSH(int data){
        this->top++;
        if(this->top == capacity){
            int *newArr = new int[2 * this->capacity];
            for(int i = 0; i < this->capacity; i++){
                *(newArr + i) = *(arr + i);
            }
            this->capacity = 2 * this->capacity;
            delete []arr;
            this->arr = newArr;
        }
        this->arr[this->top] = data;
    }
    // POP =====================================
    void POP(){
        if(top >= 0){
            top --;
        }else{
            cout<<"Stack Underflow!";
        }
    }
    // SIZE ===================================
    int SIZE(){
        if(this->top < 0){
            return 0;
        }else{
            return (this->top + 1);
        }
    }
    // TOP ====================================
    int TOP(void){
        if(this->top == -1){
            cout<< "Stack is empty!"<<endl;
            return INT_MIN;
        }else{
            return *(this->arr + this->top);
        }
    }
    // isEmpty ================================
    bool IsEmpty(void){
        if(this->top == -1){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Stack s1;
    s1.PUSH(2);
    s1.PUSH(3);
    s1.PUSH(1);
    s1.PUSH(9);
    s1.PUSH(0);
    cout<< s1.SIZE()<<endl;
    s1.PUSH(99);
    cout<< s1.SIZE()<< endl;
    s1.POP();
    cout<< s1.SIZE()<< endl;
    return 0;
}