def buildMinTree(minTree, nums, i, lo, hi):
    if lo==hi:
        minTree[i] = nums[lo]
        return
    mid = lo+(hi-lo)//2
    buildMinTree(minTree,nums,2*i+1,lo,mid)
    buildMinTree(minTree,nums,2*i+2,mid+1,hi)
    minTree[i] = min(minTree[2*i+1],minTree[2*i+2])

def updateMinTree(minTree, i, idx, val, lo, hi):
    if lo==hi:
        minTree[i] = val
        return
    mid = lo+(hi-lo)//2
    if idx<= mid: updateMinTree(minTree,2*i+1,idx,val,lo,mid)
    else: updateMinTree(minTree,2*i+2,idx,val,mid+1,hi)
    minTree[i] = min(minTree[2*i+1],minTree[2*i+2])

def getMinEle(minTree,i,lo,hi,l,r):
    if hi<l or r<lo:
        return float('inf')
    if l <= lo and hi <= r:
        return minTree[i]
    mid = lo + (hi-lo)//2
    left = getMinEle(minTree,2*i+1,lo,mid,l,r)
    right = getMinEle(minTree,2*i+2,mid+1,hi,l,r)
    return min(left,right)