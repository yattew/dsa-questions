# https://leetcode.com/problems/maximum-depth-of-binary-tree/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        depth = self.height(root)
        return depth-1
        
    def height(self,node):
        if node == None :
            return 1
        left = self.height(node.left)
        right = self.height(node.right)
        return max(left,right)+1