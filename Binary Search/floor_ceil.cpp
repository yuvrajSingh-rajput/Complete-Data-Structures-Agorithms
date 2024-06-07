#include <iostream>
#include <algorithm>
using namespace std;

//* Lets understand ceil and floor;
/* floor is the largest number in the array less than and equal to m,
for e.g.
    arr[] = {10,20,30,40,50} and m = 25
    floor(m) = 20;
    and for m = 20;
    floor(m) = 20;

ceil: ceil is basically smallest number in the array wjhich is greater than or equal to m,
for e.g.
    arr[] = {10,20,30,40,50} and m = 25
    ceil(m) = 30;
    and for m = 20
    ceil(m) = 20;

    So, basically, we can observe that ceil is lower_bound.
*/
int floor(int *arr, int n, int m)
{
    int s = 0, e = n - 1, ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] <= m)
        {
            ans = arr[mid];
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int ceil(int *arr, int n, int m)
{
    int *ptr = lower_bound(arr, arr + n, m);
    int ans = ptr - arr; //? INDEX;
    return *ptr;
}
int main()
{
    int arr[10] = {10, 20, 30, 40, 50};
    cout << floor(arr, 5, 25) << endl;
    cout << ceil(arr, 5, 25);
    return 0;
}