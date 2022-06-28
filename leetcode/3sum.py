# https://leetcode.com/problems/3sum/
class Solution(object):

    def threeSum(self, nums):
        nums.sort()
        result = []
        for num1Idx in range(len(nums) - 2):
            if num1Idx > 0 and nums[num1Idx] == nums[num1Idx - 1]:
                continue
            (num2Idx, num3Idx) = (num1Idx + 1, len(nums) - 1)

            while num2Idx < num3Idx:
                sum = nums[num1Idx] + nums[num2Idx] + nums[num3Idx]
                if sum == 0:
                    result.append((nums[num1Idx], nums[num2Idx],
                                  nums[num3Idx]))

                    num3Idx -= 1
                    while num2Idx < num3Idx and nums[num3Idx] \
                        == nums[num3Idx + 1]:
                        num3Idx -= 1
                elif sum > 0:
                    num3Idx -= 1
                else:
                    num2Idx += 1
        return result