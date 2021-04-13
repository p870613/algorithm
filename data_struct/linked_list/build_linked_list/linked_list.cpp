#include <iostream>
#include <string>
#include "node.h"
#include "head.h"

int main() {
    int n;
    std::cin >> n;
    
    Head* head = new Head();

    for(int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        Node* new_node = new Node(input);
        head->add_node(new_node);
    }
    head->print_list();
    head->del(1);
    head->print_list();
}
