#include<iostream>
using namespace std;

void average(int *array,int size){
    int sum = 0;
    for(int i=0;i<size;i++){
        sum = sum + *(array + i);
    }
    cout<< (float)sum/size;
}
int main(){
    int arr[] = {2,5,7,9,3,1};
    average(arr,6);
    return 0;
}