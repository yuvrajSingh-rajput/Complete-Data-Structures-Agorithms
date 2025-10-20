class SegmentTree {
    vector<int> seg;
    int n;
public: 
    SegmentTree(int n) {
        this->n = n;
        seg.resize(4 * n);
    }
    void build(vector<int> &arr, int index, int low, int high){
        if(low == high){
            seg[index] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(arr, 2 * index + 1, low, mid);
        build(arr, 2 * index + 2, mid + 1, high);
        seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);
    }

    bool query(int index, int low, int high, int target){
        if(seg[index] < target) return false;

        if(low == high) {
            seg[index] = -1;
            return  true;
        }

        bool placed = false;
        int mid = low + (high - low) / 2;
        if(seg[2 * index + 1] >= target){
            placed = query(2 * index + 1, low, mid, target);
        }else {
            placed = query(2 * index + 2, mid + 1, high, target);
        }

        seg[index] = max(seg[2 * index + 1], seg[2 * index + 2]);

        return placed;
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        SegmentTree st(n);
        st.build(baskets, 0, 0, n - 1);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!st.query(0, 0, n - 1, fruits[i])) ans ++;
        }
        return ans;
    }
};
