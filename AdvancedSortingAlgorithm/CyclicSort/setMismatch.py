class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        ans = [0]*2
        i = 0
        while i < n:
            correctedIdx = nums[i]-1
            if nums[i] == i+1 or nums[correctedIdx] == nums[i]: 
                i+=1
            else:
                nums[i],nums[correctedIdx] = nums[correctedIdx],nums[i]
        for i in range(n):
            if nums[i] != i+1:
                ans[0] = nums[i]
                ans[1] = i+1
                break
        return ans
        