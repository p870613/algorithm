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
    ListNode *find_middle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        ListNode *ret;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ret = slow->next;
        slow->next = NULL;
        return ret;
    }
    
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *cur = head, *next;

        while (cur != NULL) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    void merge_list(ListNode *list1, ListNode *list2)
    {
        ListNode *cur1 = list1, *cur2 = list2, *t1, *t2;

        while (cur1 != NULL && cur2 != NULL) {
            t1 = cur1->next;
            t2 = cur2->next;
            cur1->next = cur2;
            cur2->next = t1;
            cur1 = t1;
            cur2 = t2;
        }
    }

    void reorderList(ListNode* head) {
        ListNode *mid = find_middle(head);
        ListNode *head2 = reverse(mid);
        merge_list(head, head2);    
    }
};
