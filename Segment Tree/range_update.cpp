#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int arr[N], seg[4 * N], lazy[4 * N];

void build(int index, int low, int high) {
    if (low == high) {
        seg[index] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * index + 1, low, mid);
    build(2 * index + 2, mid + 1, high);
    seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
}

void lazy_update(int index, int low, int high, int l, int r, int val) {
    // Apply pending lazy updates
    if (lazy[index] != 0) {
        seg[index] += (high - low + 1) * lazy[index];
        if (low != high) {
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }

    // No overlap
    if (r < low || l > high) return;

    // Complete overlap
    if (low >= l && high <= r) {
        seg[index] += (high - low + 1) * val;
        if (low != high) {
            lazy[2 * index + 1] += val;
            lazy[2 * index + 2] += val;
        }
        return;
    }

    // Partial overlap
    int mid = (low + high) / 2;
    lazy_update(2 * index + 1, low, mid, l, r, val);
    lazy_update(2 * index + 2, mid + 1, high, l, r, val);
    seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
}

int query(int index, int low, int high, int l, int r) {
    // Apply pending lazy updates
    if (lazy[index] != 0) {
        seg[index] += (high - low + 1) * lazy[index];
        if (low != high) {
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }

    // No overlap
    if (r < low || l > high) return 0;

    // Complete overlap
    if (low >= l && high <= r) return seg[index];

    // Partial overlap
    int mid = (low + high) / 2;
    int left = query(2 * index + 1, low, mid, l, r);
    int right = query(2 * index + 2, mid + 1, high, l, r);
    return left + right;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    build(0, 0, n - 1);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            lazy_update(0, 0, n - 1, l, r, val);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(0, 0, n - 1, l, r) << endl;
        }
    }

    return 0;
}
