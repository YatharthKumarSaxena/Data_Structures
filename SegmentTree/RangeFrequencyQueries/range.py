class RangeFreqQuery:

    def __init__(self, arr):
        self.n = len(arr)
        self.freqTree = [{} for _ in range(4 * self.n)]

        self.buildFreqTree(
            0, arr, 0, self.n - 1
        )

    def addUnorderedMap(self, mp1, mp2):
        mp = {}

        for ele, freq in mp1.items():
            mp[ele] = freq

            if ele in mp2:
                mp[ele] += mp2[ele]

        for ele, freq in mp2.items():
            if ele not in mp:
                mp[ele] = freq

        return mp

    def buildFreqTree(self, i, arr, lo, hi):

        if lo == hi:
            self.freqTree[i][arr[lo]] = 1
            return

        mid = lo + (hi - lo) // 2

        self.buildFreqTree(
            2*i + 1, arr, lo, mid
        )

        self.buildFreqTree(
            2*i + 2, arr, mid + 1, hi
        )

        self.freqTree[i] = self.addUnorderedMap(
            self.freqTree[2*i + 1],
            self.freqTree[2*i + 2]
        )

    def doQuery(self, l, r, i, lo, hi, val):

        if l > hi or r < lo:
            return 0

        if l <= lo and hi <= r:
            return self.freqTree[i].get(val, 0)

        mid = lo + (hi - lo) // 2

        left = self.doQuery(
            l, r, 2*i + 1, lo, mid, val
        )

        right = self.doQuery(
            l, r, 2*i + 2, mid + 1, hi, val
        )

        return left + right

    def query(self, left, right, value):
        return self.doQuery(
            left, right, 0, 0, self.n - 1, value
        )