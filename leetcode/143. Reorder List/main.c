/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    // find middle
    struct ListNode *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    //reverse
    struct ListNode *pre = NULL, *next, *cur = slow->next;
    slow->next = NULL;
    while(cur != NULL) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    
    //MERGE
    struct ListNode *t1, *t2;
    while(head != NULL && pre != NULL) {
        t1 = head->next;
        t2 = pre->next;
        head->next = pre;
        pre->next = t1;
        head = t1;
        pre = t2;
    }
}
