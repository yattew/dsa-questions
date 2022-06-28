# https://leetcode.com/problems/intersection-of-two-arrays-ii/
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        b1 = {}
        b2 = {}
        res = []
        for i in nums1:
            b1[i] = b1.get(i,0)+1
        for i in nums2:
            b2[i] = b2.get(i,0)+1
        for i in b1.keys()&b2.keys():
            res.extend([i]*min(b1[i],b2[i]))
        return res