#include<bits/stdc++.h>
using namespace std;

class circularQueue{
    private:
    int front, rear;
    int *arr, size;
    public:
    circularQueue(){
        this->size == 1000001;
        front = -1; rear = -1;
        arr = new int[this->size];
    }
    //inserts an element in the queue.
    void enQueue(int data){
        // chacking for queue is full;
        if((this->front == 0 && this->rear == size-1)
        || ((this->rear + 1) % this->size) == this->front){
            cout << "The queue is full.";
            return;
        }else if(front == -1){
            front = 0; rear = 0;
            *(arr + this->rear) = data;
        }else if(this->rear == size-1 && !(this->front == 0)){
            rear = 0;
            arr[this->rear] = data;
        }else{
            this->rear ++;
            arr[rear] = data;
        }
    }
    // delete the front from the queue.
    int deQueue(void){
        if(front == -1){
            cout << "Queue is empty!"<<endl;
            return INT_MIN;
        }
        int ans = *(this->arr + this->front);
        arr[front] = -1;
        if(front == rear){  // condition for the single element present.
            front = -1; rear = -1;
        }else if(front == size - 1){    // to maintain the cyclic order.
            front = 0;
        }else{  // normal condition.
            front ++;
        }
        return ans;
    }
    // printing the deQueue;
    void displayDequeue(void){
        // if queue is empty.
        if(this->front == -1){
            cout << "Queue is empty!"<<endl;
            return;
        }
        else{
            if(this->front >= this->rear){
                for(int i = front; i <= this->rear; i++){
                    cout << *(this->arr + i) << " ";
                }
                cout << endl;
            }else{
                for(int i = this->front; i < this->size; i++){
                    cout<< arr[i] << " ";
                }
                for(int i = 0; i <= this->rear; i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
    }
};

int main(){
    
    return 0;
}