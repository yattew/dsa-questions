# https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution:
    def removeDuplicates(self, nums: List[int]):
        pt = 0
        while True:
            if pt+1>=len(nums):
                break
            elif nums[pt]==nums[pt+1]:
                nums.pop(pt+1)
            else:
                pt+=1
        return len(nums)