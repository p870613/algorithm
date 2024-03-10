/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *head =(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *cur_head = head;
    struct ListNode *cur1 = list1, *cur2 = list2;
    
    while(cur1 != NULL && cur2 != NULL) {
        if(cur1->val > cur2->val) {
            cur_head->next = cur2;
            cur2 = cur2->next;
        } else {
            cur_head->next = cur1;
            cur1 = cur1->next;
        }
        cur_head = cur_head->next;
    }
    if(cur1 != NULL)
        cur_head->next = cur1;
    else
        cur_head->next = cur2;

    return head->next;
}
