class Solution:
    def doRecursion(self, matchsticks, sides, index, target):
        if index == len(matchsticks):
            return True

        stick = matchsticks[index]

        for i in range(4):
            if sides[i] + stick > target:
                continue

            sides[i] += stick

            if self.doRecursion(matchsticks, sides, index + 1, target):
                return True

            sides[i] -= stick

        return False

    def makesquare(self, matchsticks):
        checkSum = 0
        n = len(matchsticks)

        if n < 4:
            return False

        for i in range(n):
            checkSum += matchsticks[i]

        if checkSum % 4 != 0:
            return False

        target = checkSum // 4

        for i in range(n):
            if matchsticks[i] > target:
                return False

        matchsticks.sort(reverse=True)

        sides = [0, 0, 0, 0]

        return self.doRecursion(matchsticks, sides, 0, target)