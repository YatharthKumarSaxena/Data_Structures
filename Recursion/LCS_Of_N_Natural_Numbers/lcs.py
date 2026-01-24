# Python3 program to print all
# increasing sequences of length
# 'k' such that the elements in
# every sequence are from first
# 'n' natural numbers.

# A utility function to 
# print contents of arr[0..k-1]
def printArr(arr, k):
    for i in range(k):
        print(arr[i], end = " ")
    print()

# A recursive function to print 
# all increasing sequences of 
# first n natural numbers. Every 
# sequence should be length k. 
# The array arr[] is used to
# store current sequence.
def printSeqUtil(i, n, k, len1, arr):
    if len1 == k:
        printArr(arr,k)
        return
    if i >= n:
        return
    i = i+1
    printSeqUtil(i,n,k,len1,arr)
    arr[len1] = i
    len1 = len1+1
    printSeqUtil(i,n,k,len1,arr)
    len1 -= 1

# This function prints all increasing 
# sequences of first n natural numbers.
# The length of every sequence must be
# k. This function mainly uses printSeqUtil()
def printSeq(n, k):
    arr = [0] * k  # An array to store
                   # individual sequences
    len1 = 0       # Initial length of
                   # current sequence
    printSeqUtil(0, n, k, len1, arr)  # Added missing parameter 'i' starting at 0

# Driver Code
k = 3 
n = 7
printSeq(n, k)