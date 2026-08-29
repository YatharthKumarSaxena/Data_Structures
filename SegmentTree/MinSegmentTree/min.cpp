#include <bits/stdc++.h>
using namespace std;

void buildMinTree(vector<int>& minTree, vector<int>& nums, int i, int lo, int hi) {
    if (lo == hi) {
        minTree[i] = nums[lo];
        return;
    }

    int mid = lo + (hi - lo) / 2;

    buildMinTree(minTree, nums, 2 * i + 1, lo, mid);
    buildMinTree(minTree, nums, 2 * i + 2, mid + 1, hi);

    minTree[i] = min(minTree[2 * i + 1], minTree[2 * i + 2]);
}

void updateMinTree(vector<int>& minTree, int i, int idx, int val, int lo, int hi) {
    if (lo == hi) {
        minTree[i] = val;
        return;
    }

    int mid = lo + (hi - lo) / 2;

    if (idx <= mid)
        updateMinTree(minTree, 2 * i + 1, idx, val, lo, mid);
    else
        updateMinTree(minTree, 2 * i + 2, idx, val, mid + 1, hi);

    minTree[i] = min(minTree[2 * i + 1], minTree[2 * i + 2]);
}

int getMinEle(vector<int>& minTree, int i, int lo, int hi, int l, int r) {
    if (hi < l || r < lo)
        return INT_MAX;

    if (l <= lo && hi <= r)
        return minTree[i];

    int mid = lo + (hi - lo) / 2;

    int left = getMinEle(minTree, 2 * i + 1, lo, mid, l, r);
    int right = getMinEle(minTree, 2 * i + 2, mid + 1, hi, l, r);

    return min(left, right);
}

int main() {
    return 0;
}