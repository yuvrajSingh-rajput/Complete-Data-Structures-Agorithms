void merge(int arr1[], int size1, int arr2[], int size2, int ans[]) {
  int i1 = 0, i2 = 0, i = 0;

  while (i1 < size1 && i2 < size2) {
    if (arr1[i1] <= arr2[i2]) {
      ans[i] = arr1[i1];
      i1++;
    } else {
      ans[i] = arr2[i2];
      i2++;
    }
    i++;
  }

  // Copy remaining elements from arr1, if any
  while (i1 < size1) {
    ans[i] = arr1[i1];
    i1++;
    i++;
  }

  // Copy remaining elements from arr2, if any
  while (i2 < size2) {
    ans[i] = arr2[i2];
    i2++;
    i++;
  }
}
