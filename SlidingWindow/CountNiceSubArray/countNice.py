from typing import List

class Solution1:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        i = 0
        j = 0
        oddCount = 0
        ans = 0
        while j < n:
            if nums[j]%2!=0: oddCount += 1
            while oddCount > k:
                if nums[i]%2!=0: oddCount -= 1
                i += 1
            copyOfI = i
            copyOfOddCount = oddCount
            while copyOfOddCount == k:
                ans += 1
                if nums[copyOfI]%2!=0: copyOfOddCount -= 1
                copyOfI += 1
            j += 1
        return ans
    
class Solution2:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        ansForK = 0
        i=0
        j=0
        oddCount = 0
        while j<n:
            if nums[j]%2 != 0: oddCount+=1
            while oddCount>k:
                if nums[i]%2 != 0: oddCount-=1
                i+=1
            ansForK += (j-i+1)
            j+=1
        ansForK_1 = 0
        oddCount = 0
        i = 0
        j = 0
        while j<n:
            if nums[j]%2 != 0: oddCount+=1
            while oddCount>k-1:
                if nums[i]%2 != 0: oddCount-=1
                i+=1
            ansForK_1 += (j-i+1)
            j+=1
        ans = ansForK - ansForK_1
        return ans

