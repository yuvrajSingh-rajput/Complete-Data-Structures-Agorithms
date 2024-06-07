int getInversions(int arr[], int n)
{
    int inv = 0; // Initialize a variable to store the count of inversions.
    for (int i = 0; i < n - 1; i++)
    {                      // Outer loop to iterate through the array.
        int min_index = i; // Initialize min_index to the current position.

        // Inner loop to find the minimum element in the unsorted portion of the array.
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {                  // Check if arr[j] is smaller than the current minimum.
                min_index = j; // Update min_index to the index of the new minimum.
            }
        }

        // Calculate and update the count of inversions.
        inv = inv + (min_index - i);

        // Swap the current element with the minimum element found.
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    return inv; // Return the total count of inversions.
}
