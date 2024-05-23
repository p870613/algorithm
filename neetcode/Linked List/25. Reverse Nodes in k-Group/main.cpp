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
    ListNode *reverse(ListNode *head) {
        ListNode *cur = head;
        ListNode *prev = NULL, *next;

        while (cur != NULL) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ret = new ListNode(0);
        ListNode *cur = head, *ret_cur = ret;
        ListNode *reverse_head = head;

        int count = 1;
        while (cur != NULL) {
            if (count == k) {
                ListNode *next = cur->next;
                ListNode *tmp;

                cur->next = NULL;
                tmp = reverse(reverse_head);
                ret_cur->next = tmp;
                ret_cur = reverse_head;

                reverse_head = next;
                cur = next;
                count = 1;
            } else {
                count ++;
                cur = cur->next;
            }   
        }
        if (reverse_head != NULL)
            ret_cur->next = reverse_head;
        return ret->next;
    }
};
