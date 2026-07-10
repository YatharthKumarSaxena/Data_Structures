from typing import List

class FindSumPairs:

    def __init__(self, nums1: List[int], nums2: List[int]):
        self.nums1 = nums1
        self.nums2 = nums2
        self.mp1 = {}
        self.mp2 = {}
        n1 = len(nums1)
        n2 = len(nums2)
        for i in range(n1): 
            self.mp1[nums1[i]] = self.mp1.get(nums1[i], 0) + 1
        for i in range(n2): 
            self.mp2[nums2[i]] = self.mp2.get(nums2[i],0) + 1

    def add(self, index: int, val: int) -> None:
        value = self.nums2[index]
        self.nums2[index] += val
        newKey = self.nums2[index]
        self.mp2[value] = self.mp2.get(value,0) - 1
        if self.mp2[value] == 0: del self.mp2[value]
        self.mp2[newKey] = self.mp2.get(newKey,0) + 1

    def count(self, tot: int) -> int:
        totalPairs = 0
        for ele in self.mp1:
            target = tot - ele
            if target in self.mp2:
                totalPairs += self.mp1[ele] * self.mp2[target]
        return totalPairs

# Your FindSumPairs object will be instantiated and called as such:
# obj = FindSumPairs(nums1, nums2)
# obj.add(index,val)
# param_2 = obj.count(tot)