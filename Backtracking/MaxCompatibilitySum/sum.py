class Solution:
    def solveByBackTrack(self, i, n, ans, currAns, score, visited):
        if i == n:
            ans[0] = max(ans[0], currAns)
            return

        for k in range(n):
            if not visited[k]:
                currAns += score[i][k]
                visited[k] = True

                self.solveByBackTrack(
                    i + 1, n, ans, currAns, score, visited
                )

                currAns -= score[i][k]
                visited[k] = False

    def maxCompatibilitySum(self, students, mentors):
        n = len(students)
        m = len(students[0])

        score = [[0] * n for _ in range(n)]

        # Build compatibility score grid
        for i in range(n):
            for j in range(n):
                for k in range(m):
                    score[i][j] += students[i][k] == mentors[j][k]

        visited = [False] * n
        ans = [0]
        currAns = 0

        self.solveByBackTrack(
            0, n, ans, currAns, score, visited
        )

        return ans[0]