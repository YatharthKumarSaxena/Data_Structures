#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> tree;

    void update(int i, int lo, int hi, int idx) {
        if (lo == hi) {
            tree[i]++;
            return;
        }

        int mid = lo + (hi - lo) / 2;

        if (idx <= mid)
            update(2*i + 1, lo, mid, idx);
        else
            update(2*i + 2, mid + 1, hi, idx);

        tree[i] = tree[2*i + 1] + tree[2*i + 2];
    }

    int query(int i, int lo, int hi, int l, int r) {
        if (l > hi || r < lo)
            return 0;

        if (l <= lo && hi <= r)
            return tree[i];

        int mid = lo + (hi - lo) / 2;

        return query(2*i + 1, lo, mid, l, r)
             + query(2*i + 2, mid + 1, hi, l, r);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        int m = sorted.size();
        tree.resize(4 * m);

        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {

            int rank = lower_bound(
                sorted.begin(), sorted.end(), nums[i]
            ) - sorted.begin();

            // values smaller than nums[i]
            ans[i] = query(0, 0, m - 1, 0, rank - 1);

            // current value add
            update(0, 0, m - 1, rank);
        }

        return ans;
    }
};