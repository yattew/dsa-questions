# https://leetcode.com/problems/squares-of-a-sorted-array/
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        l1,l2 = [],[]
        for i in nums:
            if i < 0:
                l1.insert(0,i**2)
            else:
                l2.append(i**2)
        return self.merge_sorted(l1,l2)
        
    def merge_sorted(self, l1,l2):
        res = []
        i1 = 0
        i2 = 0
        while i1<len(l1) and i2 < len(l2):
            if l1[i1] < l2[i2]:
                res.append(l1[i1])
                i1+=1
            else:
                res.append(l2[i2])
                i2+=1
        return res + l1[i1:] + l2[i2:]
            