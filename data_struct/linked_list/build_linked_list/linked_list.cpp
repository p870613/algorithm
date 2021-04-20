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
    head->reverse();
    head->print_list();
    //while(true) {
        //std::cout << "please input your choose: " << std::endl <<
                     //"1 -> add node " << std::endl <<
                     //"2 -> del node" << std::endl <<
                     //"3 -> insert node" << std::endl <<
                     //"4 -> print list" << std::endl << 
                     //"5 -> reverse list" << std::endl << 
                     //"6 -> exit" << std::endl; 
        
        //int n, pos, value;
        //Node* new_node;
        //std::cin >> n;

        //switch(n) {
            //case 1:
                //std::cout << "please input value" << std::endl;
                //std::cin >> value;
                //new_node = new Node(value);
                //head->add_node(new_node);
                //std::cout << "======== finish ========" << std::endl;
                //break;

            //case 2:
                //std::cout << "please input position you want to delete" << std::endl;
                //std::cin >> pos;
                //head->del(pos);
                //std::cout << "======== finish ========" << std::endl;
                //break;
            
            //case 3:
                //std::cout << "please input position you want to insert and its value" << std::endl;
                //std::cin >> pos >> value;
                //new_node = new Node(value);
                //head->insert(pos, new_node);
                //std::cout << "======== finish ========" << std::endl;
                //break;
            //case 4:
                //head->print_list();
                //break;
                //std::cout << "======== finish ========" << std::endl;
            //case 5:
                //head->reverse();
                //std::cout << "======== finish ========" << std::endl;
                //break;
            //case 6:
                //std::cout << "======== finish ========" << std::endl;
                //return 0;
                //break;
        //}

}
