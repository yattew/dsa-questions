# https://leetcode.com/problems/move-zeroes/
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        i=0
        j=0
        while(len(nums)>i):
            if(nums[i]!=0):
                nums[i],nums[j] = nums[j],nums[i]
                j=j+1
            i=i+1
        