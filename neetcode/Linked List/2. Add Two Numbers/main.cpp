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
        ListNode *cur1 = l1, *cur2 = l2;
        ListNode *dummy = new ListNode(0);
        ListNode* ret = dummy;
        int carry = 0;

        while(cur1 != NULL || cur2 != NULL || carry != 0) {
            int tmp = ((cur1 == NULL) ? 0 : cur1->val) + 
                      ((cur2 == NULL) ? 0 : cur2->val) +
                      carry;

            ret->next = new ListNode(tmp % 10);
            ret = ret->next;
            carry = tmp / 10;
            cur1 = (cur1 == NULL) ? 0 : cur1->next;
            cur2 = (cur2 == NULL) ? 0 : cur2->next;
        }
        return dummy->next;
    }
};
