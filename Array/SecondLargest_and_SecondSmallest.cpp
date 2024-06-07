#include <vector>
#include <iostream>
using namespace std;
#include <climits>

vector<int> getSecondOrderElements(int n, vector<int> a)
{
    // Write your code here.
    vector<int> arr;
    // For Second largest element;
    int firstLargest = INT_MIN;
    int secondLargest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > firstLargest)
        {
            secondLargest = firstLargest;
            firstLargest = a[i];
        }
        else if (a[i] > secondLargest && a[i] != firstLargest)
        {
            secondLargest = a[i];
        }
    }
    arr.push_back(secondLargest);
    // For Second smallest element;
    int firstSmallest = INT_MAX;
    int secondSmallest = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < firstSmallest)
        {
            secondSmallest = firstSmallest;
            firstSmallest = a[i];
        }
        else if (a[i] < secondSmallest && a[i] != firstSmallest)
        {
            secondSmallest = a[i];
        }
    }
    arr.push_back(secondSmallest);

    return arr;
}