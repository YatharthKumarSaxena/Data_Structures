class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        setBitVal = start^goal
        totalFlips = 0
        while setBitVal:
            totalFlips += 1
            setBitVal &= setBitVal-1
        return totalFlips