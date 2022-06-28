# https://leetcode.com/problems/remove-duplicates-from-sorted-list/
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None :
            return None
        prev = head
        current = head.next
        while current!=None:
            if prev.val == current.val:
                prev.next = current.next
                current = current.next
            else:
                prev = prev.next
                current = current.next
        return head