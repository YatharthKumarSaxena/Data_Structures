class Solution:
    def doRecursion(self, ans, arr, key, index):
        n = len(arr)
        if index == n:
            ans.append(key)
            return
        if arr[index] <= 1:
            self.doRecursion(ans, arr, key, index + 1)
            return
        offset = (arr[index]-2)*3
        if arr[index]>7: offset += 1
        limit = 3
        if arr[index]==7 or arr[index]==9: limit += 1
        for i in range(limit):
            character = chr(ord('a') + offset + i)
            self.doRecursion(ans,arr,key+character,index+1)
            
    def possibleWords(self, arr: list[int]) -> list[str]:
        # code here
        ans = []
        self.doRecursion(ans, arr, "", 0)
        return ans
