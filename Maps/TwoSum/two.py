class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        mp = {}
        n = len(nums)
        
        # Step 1: Build the map of differences
        for i in range(n):
            if target == 2*nums[i]:
                if nums[i] in mp:
                    mp[nums[i]] = [mp[nums[i]], i]
                else: 
                    mp[target-nums[i]] = i
            else: 
                mp[target-nums[i]] = i
                
        # Step 2: Check for pairs
        for e in mp:
            checkVal = target - e
            if checkVal in mp:
                if checkVal == e: 
                    if isinstance(mp[e], list): 
                        return mp[e]
                    else:
                        continue  # <--- THIS IS THE ONLY FIX YOU NEEDED!
                
                return [mp[e], mp[checkVal]]
                
        return [-1, -1]