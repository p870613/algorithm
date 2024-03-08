/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(!head || !head->next)
        return head;
    
    struct ListNode *cur = head;
    struct ListNode *prev = NULL, *next = head->next;
    
    while (cur != NULL) {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    cur->next = prev;
    return cur;
}
