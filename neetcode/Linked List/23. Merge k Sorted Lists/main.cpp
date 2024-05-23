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
    bool check_list_null(vector<ListNode*> cur) {
        for (int i = 0; i < cur.size(); i++)
            if (cur[i] != NULL)
                return false;
        return true;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret = new ListNode(0);
        ListNode* cur_ret = ret;
        vector<ListNode*> cur(lists.size(), NULL);

        for(int i = 0; i < lists.size(); i++)
            cur[i] = lists[i];

        while (true) {
            if (check_list_null(cur))
                break;
            
            ListNode *tmp = NULL;
            int index = 0;
            for (int i = 0; i < cur.size(); i++) {
                if (cur[i] != NULL) {
                    if (tmp == NULL) {
                        tmp = cur[i];
                        index = i;
                    } else {
                        if (tmp->val > cur[i]->val) {
                            tmp = cur[i];
                            index = i;
                        }                        
                    }
                }
            }
            cur_ret->next = tmp;
            cur_ret = tmp;
            cur[index] = cur[index]->next;
        }
        return ret->next;
    }
};
