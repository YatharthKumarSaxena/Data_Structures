class Solution:
    def flipBitsTillMSB(self, N):
        n = N
        temp = n

        # Highest set bit nikalna
        while n:
            temp = n
            n &= (n - 1)

        # Mask banana
        temp = temp * 2 - 1

        # Flip till MSB
        return N ^ temp