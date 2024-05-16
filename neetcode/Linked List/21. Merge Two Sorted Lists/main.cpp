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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ret = NULL, *cur1 = list1, *cur2 = list2;
        ListNode *tmp = NULL, *head = NULL;

        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        while (cur1 != NULL && cur2 != NULL) {
            if (cur1->val > cur2->val) {
                tmp = cur2;
                cur2 = cur2->next;
            } else {
                tmp = cur1;
                cur1 = cur1->next;
            }
            
            if(ret == NULL) {
                ret = tmp;
                head = ret;
            } else {
                ret->next = tmp;
                ret = ret->next;
            }
        }
        if (cur1 != NULL) 
            ret->next = cur1;
        if (cur2 != NULL)
            ret->next = cur2;
        return head;
    }
};
