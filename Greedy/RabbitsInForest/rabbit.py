class Solution:
    def numRabbits(self, answers):
        mp = {}
        ans = 0
        n = len(answers)

        for i in range(n):
            key = answers[i] + 1

            if key != 1:
                if key not in mp:
                    ans += key
                    mp[key] = 1
                else:
                    if mp[key] == key - 1:
                        del mp[key]
                    else:
                        mp[key] += 1
            else:
                ans += 1

        return ans