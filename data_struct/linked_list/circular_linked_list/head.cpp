#include "head.h"

Head::Head() {
    this->count = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

void Head::add_node(Node* node) {
    Node** cur = &head;

    if(count == 0) { 
        this->head = node;
        this->tail = node;
        this->count ++;
        return;
    }
    
    int cur_node = 0;
    while(cur_node < count) {
        if(cur_node == (count - 1)) {
            (*cur)->next = node;
            this -> tail = node;
            node -> next = head;
            this->count ++;
            return ;
        }
        cur = &((*cur)->next);
        cur_node ++;
    }
}

void Head::print_list() {
    Node** cur = &head;
   
    int cur_node = 0;
    while(cur_node  <  count) {
        std::cout << (*cur)->value << " ";
        cur = &((*cur)->next);
        cur_node ++;
    }
}

void Head::insert(int pos, Node* node) {
    Node **cur = &head;
    
    if(pos == 0){
        node->next = head;
        head = node;
        tail->next = node;
        this->count ++;
        return ;
    }else if(pos == count){
        tail->next = node;
        node -> next = head;
        this->count ++;
        return;
    } else if(pos > this->count){
        return;
    }

    for(int i = 0; i < pos-1; i++)
        cur = &((*cur)->next);

    node->next = (*cur)->next;
    (*cur)->next = node;

    this->count ++;
}

void Head::del(int pos) {
    Node **cur = &head;
    Node **pre = &head;
    this->count --;
    
    if(pos == 0){
        Node *del_node = head;
        head = head->next;
        del_node->next = nullptr;
        delete del_node;
        return ;
    }else if(pos > this->count){
        this->count ++;        
        return;
    }

    for(int i = 0; i < pos; i++){
        pre = cur;
        cur = &((*cur)->next); 
    }
    Node *del_node = *cur;
    (*pre)->next = (*cur)->next;
    del_node->next = nullptr;
    delete del_node;
}

void Head::reverse() {
    Node *cur = head;
    Node *pre = head;
    Node *next = head;
    
    while(cur != nullptr) {
        if(cur == head) {
            cur = cur ->next;
            continue;
        } 
        if(pre == head)
            (pre)->next = nullptr;

        next = cur->next;
        cur->next = pre;
        (pre) = (cur);
        (cur) = (next);
        
        if(next == nullptr) {
            head = pre;
            break;
        }
    }    
}
