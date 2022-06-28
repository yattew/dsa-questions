# https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode], curr=-1) -> int:
        if not root:return 0
        res,curr = 0,(0 if curr==-1 else curr<<1)+root.val
        res = self.sumRootToLeaf(root.left,curr)+self.sumRootToLeaf(root.right,curr)
        return res+curr if not (root.left or root.right) else res