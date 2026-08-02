from typing import List

class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:

        mp = {}

        totalDep = len(prerequisites)

        for _ in range(numCourses):
            for i in range(totalDep):
                key = prerequisites[i][0]
                val = prerequisites[i][1]

                if key not in mp:
                    mp[key] = set()

                mp[key].add(val)

                if val in mp:
                    for ele in mp[val]:
                        mp[key].add(ele)

        ans = []

        for key, val in queries:
            if key in mp and val in mp[key]:
                ans.append(True)
            else:
                ans.append(False)

        return ans