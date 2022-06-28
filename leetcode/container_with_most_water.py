# https://leetcode.com/problems/container-with-most-water/
class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height)-1
        max_area = 0
        while left<right:
            area = (right-left)*min(height[right],height[left])
            if area>max_area:
                max_area = area
            if height[right]<height[left]:
                right-=1
            else:
                left+=1
        return max_area
                