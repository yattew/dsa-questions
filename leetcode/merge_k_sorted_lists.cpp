// https://leetcode.com/problems/merge-k-sorted-lists/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];
        return recursiveMerge(lists, 0, lists.size() - 1);
    }
    ListNode* recursiveMerge(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        int m = l + (r - l) / 2;
        ListNode* LN = recursiveMerge(lists, l, m);
        ListNode* RN = recursiveMerge(lists, m + 1, r);
        return mergeTwoLists(LN, RN);
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* next_l1 = list1, * next_l2 = list2, * curr = dummy;
        while (next_l1 && next_l2) {
            if (next_l1->val < next_l2->val) {
                curr->next = next_l1;
                next_l1 = next_l1->next;
            }
            else {
                curr->next = next_l2;
                next_l2 = next_l2->next;
            }
            curr = curr->next;
        }
        if (next_l1) {
            curr->next = next_l1;
        }
        if (next_l2) {
            curr->next = next_l2;
        }
        return dummy->next;
    }
};