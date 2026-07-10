from collections import deque
from typing import List
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        qu = deque()
        deck.sort()
        n = len(deck)
        for i in range(n): qu.append(i)
        ans = [0] * n
        count = 0
        while len(qu):
            ans[qu.popleft()] = deck[count]
            if len(qu): qu.append(qu.popleft())
            count += 1
        return ans
        