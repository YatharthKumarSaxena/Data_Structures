class Solution:

    def maximizeSum(self, nums: list[int], k: int) -> int:
        """ code here """

        nums.sort()

        n = len(nums)

        cp = 0
        cn = 0
        cz = 0

        for i in range(n):
            if nums[i] < 0:
                cn += 1
            elif nums[i] > 0:
                cp += 1
            else:
                cz += 1

        maxSum = 0

        if cn == 0 and cz == 0:
            for i in range(n):
                maxSum += nums[i]

            if k % 2 == 0:
                return maxSum
            else:
                return maxSum - 2 * nums[0]

        elif cz > 0 and cp > 0 and cn == 0:
            for i in range(n):
                maxSum += nums[i]

            return maxSum

        elif cn > 0:

            if k == cn:
                for i in range(n):
                    maxSum += abs(nums[i])

                return maxSum

            elif k > cn:
                k -= cn

                if cz > 0:
                    for i in range(n):
                        maxSum += abs(nums[i])

                    return maxSum

                else:
                    minEle = float('inf')

                    for i in range(n):
                        maxSum += abs(nums[i])
                        minEle = min(abs(nums[i]), minEle)

                    if k % 2 != 0:
                        return maxSum - 2 * minEle

                    return maxSum

            else:
                for i in range(k):
                    nums[i] = -nums[i]

                for i in range(n):
                    maxSum += nums[i]

                return maxSum

        return maxSum