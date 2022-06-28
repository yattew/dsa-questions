# https://leetcode.com/problems/sqrtx/
class Solution:
    def mySqrt(self, x: int) -> int:
        low = 0
        high = x//2+2
        while True:
            mid = (low+high)//2
            if mid*mid == x:
                return mid
            elif mid*mid>x and (mid-1)*(mid-1)<x:
                return mid-1
            elif mid*mid<x and (mid+1)*(mid+1)>x:
                return mid
            elif mid*mid>x:
                high = mid-1
            else:
                low = mid+1