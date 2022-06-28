#https://leetcode.com/problems/maximum-subarray/
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        global_max = nums[0]
        current_max = nums[0]
        pt = 1
        nums_len = len(nums)
        while pt<nums_len:
            current_max = max(current_max+nums[pt],nums[pt])
            if current_max>global_max:
                global_max = current_max
            pt+=1
        return global_max
        