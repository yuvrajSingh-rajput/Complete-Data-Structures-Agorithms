#include <vector>
using namespace std;

class Solution {
private:
    int partition(vector<int>& arr, int low, int high) {
        // taking pivot as the middle element.
        int pivot = arr[low + (high - low) / 2];
        int i = low - 1;
        int j = high + 1;

        while (true) {
            do {
                ++i;
            } while (arr[i] < pivot);

            do {
                --j;
            } while (arr[j] > pivot);

            if (i >= j) {
                return j;
            }

            swap(arr[i], arr[j]);
        }
    }

    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pI = partition(arr, low, high);
            quickSort(arr, low, pI);
            quickSort(arr, pI + 1, high);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        quickSort(nums, low, high);
        return nums;
    }
};

int main(){
    // main function executed.
}