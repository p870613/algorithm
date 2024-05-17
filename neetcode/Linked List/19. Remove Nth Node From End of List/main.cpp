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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur = head, *dummy = head;
        
        while (n --)
            cur = cur->next;

        if (cur == NULL)
            return head->next;
        else
            cur = cur->next;
             
        while (cur != NULL) {
            cur = cur->next; 
            dummy = dummy->next;            
        }
        dummy->next = dummy->next->next;
        
        return head;
    }
};
