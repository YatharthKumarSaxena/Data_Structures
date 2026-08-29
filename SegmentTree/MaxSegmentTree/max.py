def buildMaxTree(maxTree, nums, i, lo, hi):
    if lo == hi:
        maxTree[i] = nums[lo]
        return

    mid = lo + (hi - lo) // 2

    buildMaxTree(maxTree, nums, 2*i + 1, lo, mid)
    buildMaxTree(maxTree, nums, 2*i + 2, mid + 1, hi)

    maxTree[i] = max(maxTree[2*i + 1], maxTree[2*i + 2])


def updateMaxTree(maxTree, i, idx, val, lo, hi):
    if lo == hi:
        maxTree[i] = val
        return

    mid = lo + (hi - lo) // 2

    if idx <= mid:
        updateMaxTree(maxTree, 2*i + 1, idx, val, lo, mid)
    else:
        updateMaxTree(maxTree, 2*i + 2, idx, val, mid + 1, hi)

    maxTree[i] = max(maxTree[2*i + 1], maxTree[2*i + 2])


def getMaxEle(maxTree, i, l, r, lo, hi):
    if l > hi or r < lo:
        return float('-inf')

    if l <= lo and hi <= r:
        return maxTree[i]

    mid = lo + (hi - lo) // 2

    left = getMaxEle(maxTree, 2*i + 1, l, r, lo, mid)
    right = getMaxEle(maxTree, 2*i + 2, l, r, mid + 1, hi)

    return max(left, right)