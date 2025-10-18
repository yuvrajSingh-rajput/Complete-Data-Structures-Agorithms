#include <bits/stdc++.h>
using namespace std;

int arr[1000005], seg[4 * 1000005];

void build(int index, int low, int high) {
  if (low == high) {
    seg[index] = arr[low];
    return;
  }
  int mid = low + (high - low) / 2;
  build(2 * index + 1, low, mid);
  build(2 * index + 2, mid + 1, high);
  seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);
}

int getMax(int index, int low, int high, int l, int r) {
  // no overlap
  if (r < low || high < l)
    return INT_MIN;

  // complete overlap
  if (l <= low && high <= r)
    return seg[index];

  // partial overlap
  int mid = low + (high - low) / 2;
  int left = getMax(2 * index + 1, low, mid, l, r);
  int right = getMax(2 * index + 2, mid + 1, high, l, r);
  return max(left, right);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  build(0, 0, n - 1); 

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    // if input is 1-based:
    // l--; r--;
    cout << getMax(0, 0, n - 1, l, r) << endl;
  }
}
