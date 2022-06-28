# https://leetcode.com/problems/merge-sorted-array/
class Solution:
    def merge(self, nums1, m: int, nums2, n: int) -> None:
        idx1, idx2, idx = m - 1, n - 1, m + n - 1
        while idx >= 0:
            if idx1 >= 0 and idx2 >= 0 and nums1[idx1] > nums2[idx2]:
                nums1[idx] = nums1[idx1]
                idx1 -= 1
            elif idx2 >= 0:
                nums1[idx] = nums2[idx2]
                idx2 -= 1
            idx -= 1
        