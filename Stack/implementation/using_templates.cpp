#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Stack{
    int capacity;
    T *arr;
    int top;
    public:
    // constructor.
    Stack(){
        this->capacity = 5;
        this->arr = new T[this->capacity];
        this->top = -1;
    }
    // PUSH ====================================
    void PUSH(T data){
        this->top++;
        if(this->top == capacity){
            T *newArr = new T[2 * this->capacity];
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
    void POP(void){
        if(top >= 0){
            top --;
        }else{
            cout<<"Stack Underflow!";
        }
    }
    // SIZE ===================================
    int SIZE(void){
        if(this->top < 0){
            return 0;
        }else{
            return (this->top + 1);
        }
    }
    // TOP ===================================
    T TOP(void){
        if(this->top < 0){
            cout<< "Stack is empty";
            return 0;   // zero is compatible for all data types.
        }else{
            return *( this->arr + this->top);
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
    Stack<int> s1;
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