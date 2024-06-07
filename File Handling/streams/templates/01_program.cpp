#include<bits/stdc++.h>
using namespace std;

template<class T>

class Vector{
    T *arr;
    int size;
    public:
    Vector(int size){
        this->size = size;
        arr = new T[size];
    }

    void input_array(void){
        cout<<"Enter the elements in the array: "<<endl;
        for(int i = 0;i<size;i++){
            cin>>this->arr[i];
        }
    }

    T dotProduct(Vector &v){
        T sum = 0;
        for(int i = 0;i<size;i++){
            sum = sum + this->arr[i] * v.arr[i];
        }
        return sum;
    }
};

int main(){
    Vector<int> vec1(3);
    vec1.input_array();
    Vector<int> vec2(3);
    vec2.input_array();
    cout<< vec1.dotProduct(vec2) <<endl;
    return 0;
}