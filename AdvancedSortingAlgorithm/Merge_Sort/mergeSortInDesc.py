class Solution:
 
    def merge(self,arr,l,r):
        temp = []
        n = r-l+1
        mid = l + (r-l)//2
        i=l
        j=mid+1
        k=0
        while i<=mid and j<=r:
            if arr[i] >= arr[j]:
                temp.append(arr[i])
                i += 1
            else:
                temp.append(arr[j])
                j += 1
            k += 1
        if k<n:
            while i<=mid:
                temp.append(arr[i])
                i += 1
            while j<=r:
                temp.append(arr[j])
                j += 1
        for k in range(n):
            arr[l+k] = temp[k]
                
        
    def mergeSort(self, arr, l, r):
        #code here
        if l >= r:
            return
        mid = l + (r-l)//2
        self.mergeSort(arr,l,mid)
        self.mergeSort(arr,mid+1,r)
        self.merge(arr,l,r)