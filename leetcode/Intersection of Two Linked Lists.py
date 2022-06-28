# https://leetcode.com/problems/intersection-of-two-linked-lists/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        node = None
        it = headA
        while headA:
            headA.val = -headA.val
            headA = headA.next
        while headB:
            if headB.val < 0:
                node = headB
                break
            headB = headB.next
        while it:
            it.val = -it.val
            it = it.next
        return node