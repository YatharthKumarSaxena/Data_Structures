from typing import List

class Solution1:
    def countReversePairs(self,nums,l,r):
        totalCrossRevPairs = 0
        mid = l+(r-l)//2
        j = mid+1
        for i in range(l,mid+1):
            while j<=r and nums[i]>2*nums[j]:
                j += 1
            totalCrossRevPairs += (j-mid-1)
        i = mid
        j = r
        n = r-l+1
        k = n-1
        temp = [0]*n
        while i>=l and j>=mid+1:
            if nums[i]>nums[j]:
                temp[k] = nums[i]
                i -= 1
            else:
                temp[k] = nums[j]
                j -= 1
            k -= 1
        while i>=l:
            temp[k] = nums[i]
            i -= 1
            k -= 1
        while j>=mid+1:
            temp[k] = nums[j]
            j -= 1
            k -= 1
        i = 0
        for i in range(n):
            nums[l+i] = temp[i]
        return totalCrossRevPairs
    def doMergeSort(self,nums,l,r):
        if l >= r:
            return 0
        mid = l + (r-l)//2
        leftRevPairs = self.doMergeSort(nums,l,mid)
        rightRevPairs = self.doMergeSort(nums,mid+1,r)
        crossRevPairs = self.countReversePairs(nums,l,r)
        totalRevPairs = leftRevPairs + crossRevPairs + rightRevPairs
        return totalRevPairs
    def reversePairs(self, nums: List[int]) -> int:
        n = len(nums)
        ans = self.doMergeSort(nums,0,n-1)
        return ans
        

class Solution2:
    def countReversePairs(self,nums,l,r):
        totalCrossRevPairs = 0
        mid = l+(r-l)//2
        j = mid+1
        for i in range(l,mid+1):
            while j<=r and nums[i]>2*nums[j]:
                j += 1
            totalCrossRevPairs += (j-mid-1)
        i = l
        j = mid+1
        n = r-l+1
        temp = []
        while i<=mid and j<=r:
            if nums[i]<nums[j]:
                temp.append(nums[i])
                i += 1
            else:
                temp.append(nums[j])
                j += 1
        while i<=mid:
            temp.append(nums[i])
            i += 1
        while j<=r:
            temp.append(nums[j])
            j += 1
        i = 0
        for i in range(n):
            nums[l+i] = temp[i]
        return totalCrossRevPairs
    def doMergeSort(self,nums,l,r):
        if l >= r:
            return 0
        mid = l + (r-l)//2
        leftRevPairs = self.doMergeSort(nums,l,mid)
        rightRevPairs = self.doMergeSort(nums,mid+1,r)
        crossRevPairs = self.countReversePairs(nums,l,r)
        totalRevPairs = leftRevPairs + crossRevPairs + rightRevPairs
        return totalRevPairs
    def reversePairs(self, nums: List[int]) -> int:
        n = len(nums)
        ans = self.doMergeSort(nums,0,n-1)
        return ans
        