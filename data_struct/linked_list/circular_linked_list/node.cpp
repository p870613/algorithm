#include "node.h"

Node::Node(int value){
    this->value = value;
    this->next = nullptr;
}

Node::Node(int value, Node* next){
    this->value = value;
    this->next = next;
}

Node* Node::get_next(){
    return this->next;
}

int Node::get_value(){
    return this->value;
}
