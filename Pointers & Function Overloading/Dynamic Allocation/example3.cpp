#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T; // Read the number of test cases

    while (T--) {
        int row, col;
        cin >> row >> col;

        // Check for invalid row or col values
        if (row <= 0 || col <= 0) {
            continue; // Skip this test case
        }

        // Allocate memory for the original matrix and the transpose
        int** matrix = new (nothrow) int*[row]; // Use (nothrow) to check for allocation failure
        int** transpose = new (nothrow) int*[col];

        if (matrix == nullptr || transpose == nullptr) {
            break; // Exit the program with an error
        }

        // Allocate memory for rows of the transpose
        for (int i = 0; i < col; i++) {
            transpose[i] = new (nothrow) int[row];
            if (transpose[i] == nullptr) {
                break; // Exit the program with an error
            }
        }

        // Read values into the original matrix
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> matrix[i][j];
            }
        }

        // Transpose the matrix
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                transpose[j][i] = matrix[i][j];
            }
        }

        // Print the transposed matrix
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                cout << transpose[i][j] << " ";
            }
            cout << endl;
        }

        // Deallocate memory for the transpose and the original matrix
        for (int i = 0; i < col; i++) {
            delete[] transpose[i];
        }

        delete[] transpose;
        for (int i = 0; i < row; i++) {
            delete[] matrix[i];
        }

        delete[] matrix;
    }

    return 0;
}
