#include <iostream>
#include <vector>
using namespace std;

/*
    "start" points to the position where we want to place the next 0, "mid" is used to scan through the array, and "end" points to the
    position where we want to place the next 2.
*/

void Sort012(vector<int> &arr)
{
    int start = 0, mid = 0, end = arr.size() - 1;

    while (mid <= end)
    {
        if (arr[mid] == 0)
        {
            swap(arr[start], arr[mid]);
            start++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[end]);
            end--;
        }
    }
}

int main()
{

    vector<int> arr = {1, 2, 0, 0, 0, 2, 1, 1, 2, 2, 1, 1, 1, 0};

    Sort012(arr);

    cout << "The sorted array is: " << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
