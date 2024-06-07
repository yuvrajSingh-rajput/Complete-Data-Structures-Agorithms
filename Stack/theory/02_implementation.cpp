#include<bits/stdc++.h>
using namespace std;

class Stack{

    private:
    int size;
    int *arr;
    int top = -1;

    public:
    Stack(int s):size(s){};

    void push(int data){
        if(size - top > 1){
            top ++;
            arr[top] = data;
        }else{
            cout<<"Stack overflow"<<endl;
        }
    }

    void pop(void){
        if(top>=0){
            top--;
        }else{
            cout<<"Stack underflow"<<endl;
        }
    }

    void empty(void){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
        }else{
            cout<<"Stack is not empty"<<endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }else{
            cout<<"Stack is empty hence top is not defined"<<endl;
        }
    }
};

int main(){
    
    return 0;
}