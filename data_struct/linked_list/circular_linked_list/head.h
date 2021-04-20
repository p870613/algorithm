#include <iostream>
#include "node.h"
#ifndef _HEAD_H
#define _HEAD_H


class Head {
    private:
        int count;
        class Node* head;
        class Node* tail;
    public:
        Head();
        void add_node(Node*);
        void print_list();
        void insert(int, Node*);
        void del(int);   
        void reverse();
};
#endif

