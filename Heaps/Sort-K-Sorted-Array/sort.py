import heapq

class Solution:
    def nearlySorted(self, arr, k):  
        #code here
        n = len(arr);
        ans = [0] * n
        heap = []
        j=0
        for i in range(n):
            if len(heap) > k+1:
                ans[j] = heap[0]
                heapq.heappop(heap)
                j += 1
            heapq.heappush(heap,arr[i])
        while len(heap):
            ans[j] = heap[0];
            heapq.heappop(heap)
            j += 1
        for i in range(n):
            arr[i] = ans[i]