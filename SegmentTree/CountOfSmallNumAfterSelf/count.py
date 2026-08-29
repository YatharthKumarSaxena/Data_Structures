class Solution:

    def __init__(self):
        self.tree = []

    def update(self, i, lo, hi, idx):
        if lo == hi:
            self.tree[i] += 1
            return

        mid = lo + (hi - lo) // 2

        if idx <= mid:
            self.update(2*i + 1, lo, mid, idx)
        else:
            self.update(2*i + 2, mid + 1, hi, idx)

        self.tree[i] = self.tree[2*i + 1] + self.tree[2*i + 2]

    def query(self, i, lo, hi, l, r):
        if l > hi or r < lo:
            return 0

        if l <= lo and hi <= r:
            return self.tree[i]

        mid = lo + (hi - lo) // 2

        return (
            self.query(2*i + 1, lo, mid, l, r)
            + self.query(2*i + 2, mid + 1, hi, l, r)
        )

    def countSmaller(self, nums):
        n = len(nums)

        sorted_nums = nums[:]
        sorted_nums.sort()

        # Remove duplicates
        sorted_nums = list(set(sorted_nums))
        sorted_nums.sort()

        m = len(sorted_nums)

        self.tree = [0] * (4 * m)

        ans = [0] * n

        for i in range(n - 1, -1, -1):

            # Find rank
            lo = 0
            hi = m - 1

            while lo <= hi:
                mid = lo + (hi - lo) // 2

                if sorted_nums[mid] < nums[i]:
                    lo = mid + 1
                else:
                    hi = mid - 1

            rank = lo

            # Count smaller elements
            ans[i] = self.query(
                0, 0, m - 1,
                0, rank - 1
            )

            # Add current element
            self.update(
                0, 0, m - 1,
                rank
            )

        return ans