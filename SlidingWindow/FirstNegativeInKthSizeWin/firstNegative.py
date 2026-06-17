#User function Template for python3

class Solution:
    def firstNegInt(self, arr, k): 
         # code here 
        n = len(arr)
        negIdx = -1
        ans = [0] * (n-k+1)
        for i in range(k):
            if arr[i]<0:
                negIdx = i
                ans[0] = arr[negIdx]
                break
        for i in range(1,n-k+1):
            if negIdx >= i:
                ans[i] = arr[negIdx]
            else:
                p = i
                while p<i+k:
                    if arr[p]<0:
                        negIdx = p
                        ans[i] = arr[negIdx]
                        break
                    p += 1
        return ans
    

