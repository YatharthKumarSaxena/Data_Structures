import heapq

class Solution:
   
    #Function to sort the array according to frequency of elements.
    def sortByFreq(self,arr):
        #code here
        mp = dict()
        n = len(arr)
        pq = []
        for i in range(n):
            mp[arr[i]] = mp.get(arr[i],0)+1
        ans = []
        for ele,count in mp.items():
            heapq.heappush(pq,(-count,ele))
        while len(pq):
            count,ele = pq[0]
            heapq.heappop(pq)
            while mp[ele]:
                mp[ele] = mp.get(ele,0)-1
                ans.append(ele)
            del mp[ele]
        return ans