from typing import List

class Solution1:
    def longestOnes(self, nums: List[int], k: int) -> int:
        n = len(nums)
        noOfZeros = 0
        if k >= n: return n
        for i in range(n):
            if not nums[i]: noOfZeros += 1
        if k >= noOfZeros: return n
        if k==0:
            maxLen = -float('inf')
            currLen = 0
            for i in range(n):
                if nums[i]: currLen += 1
                else: 
                    maxLen = max(currLen,maxLen)
                    currLen = 0
            maxLen = max(currLen,maxLen)
            return maxLen
        i = 0
        j = 0
        flips = 0
        maxLen = -float('inf')
        currLen = -float('inf')
        while j<n:
            if nums[j]: j += 1
            else:
                if flips < k:
                    flips += 1
                    j += 1
                else:
                    currLen = j-i
                    maxLen = max(currLen,maxLen)
                    while nums[i]: i += 1
                    i += 1
                    j += 1
        currLen = j-i
        maxLen = max(currLen,maxLen)
        return maxLen
    


class Solution2:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        zeroPos = -1
        i = 0
        j = 0
        count = 0
        maxLen = -float('inf')
        while j<n:
            prev = zeroPos
            if not nums[j]:
                count += 1
                zeroPos = j
            if count<=1: j+=1
            else:
                maxLen = max(maxLen,j-i)
                count -= 1
                i = prev+1
                j += 1
        maxLen = max(maxLen,j-i)
        return maxLen-1