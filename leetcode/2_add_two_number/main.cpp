#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void Create_list(int, ListNode**);
void Print_list(ListNode **);
void Add_list(ListNode*, ListNode*);

void Add_list(ListNode* l1, ListNode* l2){
    ListNode *cur_l1 = l1;
    ListNode *cur_l2 = l2;
    ListNode *head = NULL;
    ListNode *cur = NULL;
    int add = 0;
    while(cur_l1 != NULL || cur_l2 != NULL || add != 0){
        int l1_val, l2_val;
        if(cur_l1 == NULL){
            l1_val = 0;
        }else{
            l1_val = cur_l1 ->val;
        }
        if(cur_l2 == NULL){
            l2_val = 0;
        }else{
            l2_val = cur_l2 ->val;
        }

        std::cout << l1_val << " " << l2_val << std::endl;

        int sum = l1_val + l2_val + add;
        add = 0;
        if(sum >= 10){
            add = sum / 10;
            sum = sum % 10;
        }
        
        ListNode *node = new ListNode(sum);
        if(head == NULL){
            head = node;
            cur = node;
        }else{
            cur->next = node;
            cur = node;
        }

        if(cur_l1 != NULL)
            cur_l1 = cur_l1 ->next;
        if(cur_l2 != NULL)
            cur_l2 = cur_l2 ->next;
    }
    Print_list(&head);
}
void Create_list(int n, ListNode **head){
    ListNode *cur = NULL;
    while(n > 0){
        int val = n % 10;
        ListNode *node = new ListNode(val);
        if(cur == NULL){
            *head = node;
            cur = node;
        }else{
            cur->next = node;
            cur = node;
        }
        n = n / 10;
    }
}

void Print_list(ListNode **head){
    ListNode **cur = head;
    while(*cur){
        std::cout << (*cur)->val << " ";
        cur =&((*cur)->next);
    }
    std::cout << std::endl;
}
int main(){
    int n1, n2;
    std::cin >> n1 >> n2;
    ListNode *l1_head = NULL;
    ListNode *l2_head = NULL;
    Create_list(n1, &l1_head);
    Create_list(n2, &l2_head);
    Print_list(&l1_head);
    Print_list(&l2_head);

    Add_list(l1_head, l2_head);
}
