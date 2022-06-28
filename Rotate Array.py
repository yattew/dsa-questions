# https://leetcode.com/problems/rotate-array/
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        if k==0 or len(nums)==1:
            nums[:]=nums
        elif k>len(nums):
            k=k%len(nums)
            nums[:]=nums[-k:] + nums[:len(nums)-k]
        else:            
            nums[:]=nums[-k:] + nums[:len(nums)-k]