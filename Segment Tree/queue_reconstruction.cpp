class SegmentTree {
    vector<int> seg;
public:
    SegmentTree(int n) {
        seg.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    void build(int i, int low, int high) {
        if (low == high) {
            seg[i] = 1;
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * i + 1, low, mid);
        build(2 * i + 2, mid + 1, high);
        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
    }

    int query(int i, int low, int high, int target) {
        if (low == high) {
            seg[i] = 0;
            return low;
        }

        int mid = low + (high - low) / 2;
        int ans;
        if (seg[2 * i + 1] >= target)
            ans = query(2 * i + 1, low, mid, target);
        else
            ans = query(2 * i + 2, mid + 1, high, target - seg[2 * i + 1]);

        seg[i] = seg[2 * i + 1] + seg[2 * i + 2];
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [&](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = people.size();
        SegmentTree st(n);

        vector<vector<int>> ans(n);
        for (int i = 0; i < n; i++) {
            int index = st.query(0, 0, n - 1, people[i][1] + 1);
            ans[index] = people[i];
        }

        return ans;
    }
};
