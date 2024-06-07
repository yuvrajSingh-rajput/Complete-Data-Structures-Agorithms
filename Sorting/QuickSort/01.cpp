#include<bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& arr, int low, int high){
    int pivot = arr[low], i = low, j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }
        while(arr[j] > pivot && j >= low + 1){
            j--;
        }
        if(i < j){
            swap(arr[i], arr[j]);  // Corrected line
        }
    }
    swap(arr[low], arr[j]);
    return j;
}


void qs(vector<int>& arr, int low, int high){
    if(low >= high){
        return;
    }else{
        int pIdx = pivotIndex(arr, low, high);
        qs(arr, low, pIdx-1);
        qs(arr, pIdx + 1, high);
    }
}

void quickSort(vector<int>& arr){
    int low = 0, high = arr.size() - 1;
    qs(arr, low, high);
}

void printArray(vector<int>& arr){
    for(auto &i : arr){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {12, 0, -1, 89, 12, 4, 2, 5};
    cout<< "Before the sorting: \n";
    printArray(arr);
    quickSort(arr);
    cout<< "After the sorting: \n";
    printArray(arr);
    return 0;
}