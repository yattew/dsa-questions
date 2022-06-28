# https://leetcode.com/problems/remove-element/
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        pt = 0
        while pt<len(nums):
            if nums[pt] == val:
                nums.pop(pt)
                continue
            pt+=1
        return len(nums)
        