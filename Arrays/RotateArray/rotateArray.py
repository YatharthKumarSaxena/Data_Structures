from typing import List

class Solution:
    def reversePartOfArray(self, arr: List[int], start: int, end : int) -> None:
        if start < 0 or end >= len(arr): return
        arr[start:end+1] = arr[start:end+1][::-1]

    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k%n
        self.reversePartOfArray(nums,0,n-k-1)    
        self.reversePartOfArray(nums,n-k,n-1)    
        self.reversePartOfArray(nums,0,n-1)