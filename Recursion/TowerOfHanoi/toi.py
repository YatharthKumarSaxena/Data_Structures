class Solution1:
    def  towerOfHanoi(self, n, fromm, to, aux):
        # code here
        return pow(2,n)-1
    
class Solution2:
    def towerOfHanoi(self, n, fromm, to, aux):
        if n == 0:
            return 0

        left = self.towerOfHanoi(n-1, fromm, aux, to)
        move = 1
        right = self.towerOfHanoi(n-1, aux, to, fromm)

        return left + move + right
