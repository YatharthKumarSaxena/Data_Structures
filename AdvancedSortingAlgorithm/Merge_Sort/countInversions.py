class Solution:
    def countInversions(self,arr,left,mid,right):
        n1 = mid-left+1
        n2 = right-mid
        L = [0]*n1
        R = [0]*n2
        for i in range(n1):
            L[i]=arr[left+i]
        for j in range(n2):
            R[j]=arr[mid+1+j]
        count = 0
        k = left
        i = 0
        j = 0
        while i<n1 and j<n2:
            if L[i]>R[j]:
                count += (n1-i)
                arr[k]=R[j]
                k+=1
                j+=1
            else:
                arr[k]=L[i]
                k+=1
                i+=1
        while i<n1:
            arr[k] = L[i]
            k+=1
            i+=1
        while j<n2:
            arr[k] = R[j]
            k+=1
            j+=1
        return count
    
    def doMergeSort(self,arr,left,right):
        if left>=right:
            return 0
        mid = left + (right-left)//2
        count = 0
        count += self.doMergeSort(arr,left,mid)
        count += self.doMergeSort(arr,mid+1,right)
        count += self.countInversions(arr,left,mid,right)
        return count
        
    def inversionCount(self, arr):
        # Code Here
        return self.doMergeSort(arr,0,len(arr)-1)