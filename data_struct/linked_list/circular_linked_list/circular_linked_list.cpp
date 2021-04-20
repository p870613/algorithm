#include <iostream>
#include <string>
#include "node.h"
#include "head.h"

int main() {
    Head* head = new Head();
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        int input;
        std::cin >> input;
        Node* new_node = new Node(input);
        head->add_node(new_node);
    }

    head->print_list();
    std::cout << std::endl;
    Node* new_node = new Node(100);
    head->insert(4, new_node);
    head->print_list();
    //head->reverse();
    //head->print_list();
}
