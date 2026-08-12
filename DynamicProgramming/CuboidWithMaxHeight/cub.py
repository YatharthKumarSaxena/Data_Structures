class Solution:
    def maxHeight(self, height, width, length):
        n = len(height)

        cuboids = []

        for i in range(n):

            # Orientation 1
            cuboids.append([
                min(width[i], length[i]),
                max(width[i], length[i]),
                height[i]
            ])

            # Orientation 2
            cuboids.append([
                min(height[i], length[i]),
                max(height[i], length[i]),
                width[i]
            ])

            # Orientation 3
            cuboids.append([
                min(height[i], width[i]),
                max(height[i], width[i]),
                length[i]
            ])

        cuboids.sort()

        m = len(cuboids)
        dp = [0] * m

        maxHeight = 0

        for i in range(m):

            dp[i] = cuboids[i][2]

            for j in range(i):

                if (cuboids[j][0] < cuboids[i][0] and
                    cuboids[j][1] < cuboids[i][1]):

                    dp[i] = max(
                        dp[i],
                        dp[j] + cuboids[i][2]
                    )

            maxHeight = max(maxHeight, dp[i])

        return maxHeight