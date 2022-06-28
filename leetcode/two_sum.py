# https://leetcode.com/problems/two-sum/
class Solution:
    def twoSum(self, nums, target: int):
        n_set = {target-nums[0]:0}
        for i in range(1,len(nums)):
            if nums[i] in n_set:
                return [n_set[nums[i]],i]
            n_set[target-nums[i]] = i