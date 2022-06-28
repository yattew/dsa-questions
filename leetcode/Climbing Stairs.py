# https://leetcode.com/problems/climbing-stairs/
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1 or n == 2 or n == 3:
            return n
        else:
            res = [3,5]
            for i in range(5, n+1):
                temp = res[1]
                res[1] = res[0]+res[1] 
                res[0] = temp
            if n == 4:
                return 5
            return res[1]