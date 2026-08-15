class Solution:
    def minCost(self, n, m, x, y):
        x.sort(reverse=True)
        y.sort(reverse=True)

        arrX = x
        arrY = y

        horPiece = 1
        verPiece = 1
        horIn = 0
        verIn = 0
        ans = 0

        n = len(x)
        m = len(y)

        while horIn < n and verIn < m:
            if arrX[horIn] > arrY[verIn]:
                # x = vertical cut
                ans += horPiece * arrX[horIn]
                horIn += 1
                verPiece += 1
            else:
                # y = horizontal cut
                ans += verPiece * arrY[verIn]
                verIn += 1
                horPiece += 1

        while horIn < n:
            ans += horPiece * arrX[horIn]
            horIn += 1
            verPiece += 1

        while verIn < m:
            ans += verPiece * arrY[verIn]
            verIn += 1
            horPiece += 1

        return ans