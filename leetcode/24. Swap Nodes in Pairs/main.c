/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(!head||!head->next) return head;
    
    struct ListNode *ret = (struct ListNode*) malloc(sizeof(struct ListNode));
    
    struct ListNode *cur = head;
    struct ListNode *pre = ret;
    
    ret->next = pre;
    while(cur != NULL && cur->next != NULL) {
        pre->next = cur->next;
        cur->next = pre->next->next;
        pre->next->next = cur;

        pre = cur;
        cur = cur->next;
    }
    return ret->next;
}
