#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int key)
{
    int start = 0, end = n - 1, mid, index = 0;
    mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            index = mid;
            end = mid - 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    if (index != 0)
    {
        return index;
    }
    else
    {
        return 0;
    }
}
int lastOccurrence(int arr[], int n, int key)
{
    int start = 0, end = n - 1, mid, index = 0;
    mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            index = mid;
            start = mid + 1;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    if (index != 0)
    {
        return index;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int arr[7] = {2, 4, 10, 10, 10, 11, 20};
    int count;
    firstOccurrence(arr, 7, 10);
    lastOccurrence(arr, 7, 10);
    if (firstOccurrence(arr, 7, 10) == 0 && lastOccurrence(arr, 7, 10) == 0)
    {
        count = 0;
    }
    else
    {
        count = (lastOccurrence(arr, 7, 10) - firstOccurrence(arr, 7, 10)) + 1;
    }
    cout << "The number of times the the serched key is present = " << count;
    return 0;
}