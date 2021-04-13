#ifndef _NODE_H
#define _NODE_H
#include "head.h"

class Node {
    private:
        Node *next;
        int value;
    public:
        Node(int);
        Node(int, Node*);
        Node* get_next();
        int get_value();

    friend class Head;
};

#endif
