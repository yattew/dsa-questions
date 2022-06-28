// https://leetcode.com/problems/add-two-numbers/submissions/


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*ret = NULL;
        ListNode*pt = NULL;
        int carry = 0;
        while(l1||l2)
        {
            if(ret == NULL)
            {
                carry = (l1->val+l2->val)/10;
                ret = new ListNode((l1->val+l2->val)%10);
                pt = ret;
            }
            else
            {
                int s = 0;
                if(l1) s+=l1->val;
                if(l2) s+=l2->val;
                s+=carry;
                carry = s/10;
                pt->next = new ListNode(s%10);
                pt = pt->next;
            }
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry)
        {
            pt->next = new ListNode(carry);
        }
        return ret;
    }
};