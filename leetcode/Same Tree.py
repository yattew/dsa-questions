# https://leetcode.com/problems/same-tree/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        self.flag = True
        self.check(p,q)
        return self.flag
        
        
    def check(self,p,q):
        if p and q:
            if p.val != q.val:
                self.flag = False
                return
        else:
            if p:
                self.flag = False
            elif q:
                self.flag = False
            return
        self.check(p.left,q.left)
        self.check(p.right,q.right)