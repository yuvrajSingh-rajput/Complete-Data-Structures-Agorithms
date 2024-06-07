#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>&arr) {
    // Write your code here.
    for(int i=0;i<arr.size()-1;i++){
        int minIndex = i;
        for(int j=i;j<arr.size();j++){
            if(arr[minIndex]>arr[j]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}
int main()
{
    vector<int> v = {12, 34, 56, 23, 11};
    selectionSort(v);
    cout << "The Sorted array is: " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}