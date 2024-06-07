#include <iostream>
using namespace std;

int main() {
    int T; // Initialize the number of test cases
    cin >> T; // Read the number of test cases

    while (T--) {
        int size;
        cin >> size;

        int* array = new int[size];
        for (int i = 0; i < size; i++) {
            cin >> *(array + i);
        }

        int* arr = new int[size];
        int i1 = 0;

        for (int i = 0; i < size; i++) {
            if (*(array + i) != 0) {
                *(arr + i1) = *(array + i);
                i1++;
            }
        }

        // Fill the remaining positions with zeros
        for (int i = i1; i < size; i++) {
            *(arr + i) = 0;
        }

        for (int i = 0; i < size; i++) {
            cout << *(arr + i) << " ";
        }
        cout<<endl;
        delete[] array;
        delete[] arr;
    }

    return 0;
}