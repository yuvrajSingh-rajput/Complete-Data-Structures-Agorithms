#include<iostream>
#include<vector>
using namespace std;

//*| * Always remember the sorted card example. By taking one by one and arranging then in sorted order.
/* |
   | 1. There will be two parts in the array one is sorted part (or that part from which we are comparing) and second is non sorted part.
   | 2. First element will always be sorted i.e. we will start comparing second element from first element in round 1;
   | 3. There will be total [N-1] rounds.
   | 4. We shift that element toward right, between which our iterating element comes, To create an extra space for that element.
   | */

//! Basically in this technique: It always takes an element and place it in to correct position.



void InsertionSort(vector<int>& arr){
    //* For number of rounds
    for(int i=1;i<arr.size();i++){

        int temp = arr[i],j;  // This is compairing.

        for(j=i-1;j>=0;j--){    //From which it is comparing.

            if(arr[j]>temp){
                //* SHIFT;
                arr[j+1] = arr[j];
            }
            else{
                break;  // Ruk jao.
            }
        }
        arr[j+1] = temp;
    }
}


//TODO: Method 2:
void insertionSort(std::vector<int> &arr) {
    int n = arr.size(); // Get the number of elements in the array

    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Store the current element to be inserted
        int j = i - 1;    // Start with the previous element

        // Compare the current element with elements to its left and move them to the right
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift the greater element to the right
            j--;                // Move to the previous element
        }

        arr[j + 1] = key; // Insert the current element into its correct position
    }
}

int main(){
    vector<int>array = {10,1,7,4,8,2,11};
    InsertionSort(array);
    cout<<"The Sorted array will be: "<<endl;
    for(int i=0;i<array.size();i++){
        cout<<array[i]<<" ";
    }
    return 0;
}

//! space complexity: O(1);
//! time complexity: O(n)[best case] && O(n*n)[worst case]