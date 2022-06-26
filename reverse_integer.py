# https://leetcode.com/problems/reverse-integer/
class Solution:
    def reverse(self, x: int) -> int:
        i = 0
        l = 2**31
        s = str(x)
        if s[0] == '-':
            i = int('-'+s[-1:0:-1])
        else: i = int(s[::-1])
        if i<-l or i>l-1:
            return 0
        else: return i
        