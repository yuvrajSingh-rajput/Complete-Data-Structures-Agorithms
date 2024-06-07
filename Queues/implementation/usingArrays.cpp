#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int *arr, front, rear, capacity;
    Queue()
    {
        this->capacity = 5;
        this->arr = new int[this->capacity];
        this->front = 0;
        this->rear = 0;
    }
    int getSize()
    {
        return this->rear;
    }
    bool isEmpty()
    {
        return this->rear == 0;
    }
    void enqueue(int data)
    {
        if (this->rear == this->capacity)
        {
            int *newarr = new int[this->capacity * 2];
            for (int i = 0; i < this->capacity; i++)
            {
                *(newarr + i) = *(this->arr + i);
            }
            delete[] this->arr;
            this->arr = newarr;
        }
        this->arr[this->rear] = data;
        this->rear++;
    }

    int dequeue()
    {
        if (this->front == this->rear)
        {
            cout << "The queue is already empty!" << endl;
            return -1;
        }
        int ans = this->arr[this->front];
        for(int i = 0; i < this->rear - 1; i ++){
           this->arr[i] == arr[i + 1];
        }
        this->rear--;
        return ans;
    }

    int Front()
    {
        if (this->front == this->rear)
        {
            cout << "The queue is empty!" << endl;
            return 0;
        }
        else
        {
            return this->arr[this->front];
        }
    }
    void display()
    {
        if (front != -1)
        {
            for (int i = this->front; i < this->rear; i++)
            {
                cout << this->arr[i] << " ";
            }
            cout << "\n";
        }
        else
        {
            cout << "The queue is EMPTY!!" << endl;
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(2);
    q.enqueue(3);
    cout << q.Front() << endl;
    q.display();
    cout << q.dequeue() << endl;
    q.display();
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
    q.dequeue();
    cout << q.isEmpty() << endl;
    return 0;
}