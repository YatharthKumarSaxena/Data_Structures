class Solution:
    def getMaxOccurringChar(self, s):
        #code here
        t = "".join(sorted(s))
        count = 1
        maxCount = 1
        ans = t[0]
        curr = t[0]
        for i in range(1,len(s)):
            if curr != t[i]:
                if count > maxCount:
                    maxCount = count
                    ans = curr
                count = 1
                curr = t[i]
            else: count += 1
        if count>maxCount:
            ans = curr
        return ans