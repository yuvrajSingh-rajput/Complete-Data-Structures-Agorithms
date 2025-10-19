#include <bits/stdc++.h>
using namespace std;

int arr[1000005], seg[4 * 1000005];

void build(int index, int low, int high){
    if(low == high){
        seg[index] = arr[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * index + 1, low, mid);
    build(2 * index + 2, mid + 1, high);
    seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
}

void point_update(int index, int low, int high, int node, int val){
    if(low == high){
        seg[index] += val;
        return;
    }

    int mid = low + (high - low) / 2;
    if(node <= mid)
        point_update(2 * index + 1, low, mid, node, val);
    else
        point_update(2 * index + 2, mid + 1, high, node, val);

    seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
}

int query(int index, int low, int high, int l, int r){
    if(l > high || r < low) return 0; 
    if(l <= low && high <= r) return seg[index]; 

    int mid = low + (high - low) / 2;
    int left = query(2 * index + 1, low, mid, l, r);
    int right = query(2 * index + 2, mid + 1, high, l, r);
    return left + right;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    build(0, 0, n - 1);

    int q;
    cin >> q;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1){
            int idx, val;
            cin >> idx >> val;
            point_update(0, 0, n - 1, idx, val);
        }else{
            int l, r;
            cin >> l >> r;
            cout << query(0, 0, n - 1, l, r) << endl;
        }
    }

    return 0;
}
