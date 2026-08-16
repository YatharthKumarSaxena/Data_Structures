class Solution:
    def minPlatform(self, arr: list[int], dept: list[int]) -> int:
        arr.sort()
        dept.sort()

        i = 0
        j = 0
        n = len(arr)

        maxPlatforms = 0
        currPlatforms = 0

        while i < n and j < n:
            if arr[i] <= dept[j]:
                i += 1
                currPlatforms += 1
                maxPlatforms = max(maxPlatforms, currPlatforms)
            else:
                currPlatforms -= 1
                j += 1

        return maxPlatforms