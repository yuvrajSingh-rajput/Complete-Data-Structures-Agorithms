#include <iostream>
using namespace std;

// binary search is only used for sorted array;

// Time complexity of binary search is O(log N);

// Time complexity of linear search algorithm is O(N);
/* NOTE:--------> In linear search if we are doing the problem of first and last occurrence of a user input key, then always keep in   mind linear search algorithm search the element in revese order -> It simply means if you want to search the first occurrence then put limit from (int i=N-1;i>=0;i--) and vice versa for the last occurrence. */

int binarySearch(int arr[], int size, int key)
{

    int start = 0, end = size - 1;

    int mid = (start) + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start) + (end - start) / 2;
    }
    return -1;
}
int main()
{
    int odd[7] = {2, 4, 6, 8, 10, 16, 90};
    int even[6] = {-2, 78, 433, 567, 999, 1000};

    cout << "The index of " << 8 << " is " << binarySearch(odd, 7, 8) << endl;
    cout << "The index of " << 433 << " is " << binarySearch(even, 6, 433) << endl;
}