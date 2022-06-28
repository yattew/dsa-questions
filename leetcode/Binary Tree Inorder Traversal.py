# https://leetcode.com/problems/binary-tree-inorder-traversal/
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root:
            l = []
            self.recurse(root,l)
            return l
        return []
    def recurse(self,node,l):
        if node.left:
            self.recurse(node.left,l)
        l.append(node.val)
        if node.right:
            self.recurse(node.right,l)