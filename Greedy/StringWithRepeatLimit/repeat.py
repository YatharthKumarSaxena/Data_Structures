import heapq
from collections import Counter

class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        freq = Counter(s)

        # Python heap is min-heap, so use negative ord
        pq = []
        for ch, count in freq.items():
            heapq.heappush(pq, (-ord(ch), count))

        ans = []

        while pq:
            neg_char, count = heapq.heappop(pq)
            largest_char = chr(-neg_char)

            use = min(repeatLimit, count)

            ans.append(largest_char * use)
            count -= use

            if count > 0:
                # No smaller character available
                if not pq:
                    break

                neg_second, second_count = heapq.heappop(pq)
                second_char = chr(-neg_second)

                # Use one smaller character as separator
                ans.append(second_char)
                second_count -= 1

                if second_count > 0:
                    heapq.heappush(pq, (neg_second, second_count))

                # Put remaining largest characters back
                heapq.heappush(pq, (neg_char, count))

        return ''.join(ans)