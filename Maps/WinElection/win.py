class Solution:
    def winner(self, arr, n):
        mp = {}

        for name in arr:
            mp[name] = mp.get(name, 0) + 1

        ans = arr[0]
        maxVote = float('-inf')

        for name, votes in mp.items():
            if votes > maxVote:
                maxVote = votes
                ans = name
            elif votes == maxVote:
                if name < ans:
                    ans = name

        return [ans, str(maxVote)]