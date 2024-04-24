struct node {
    int value;
    int min;
};

class MinStack {
public:
    vector <struct node*> sta;
    MinStack() { 
        
    }
    
    void push(int val) {
        struct node* new_node = new (struct node);
        new_node->value = val;
        if((sta.size() == 0) || (sta.size() != 0 && sta.back()->min > val))
            new_node->min = val;
        else
            new_node->min = sta.back()->min;
        sta.push_back(new_node); 
    }
    
    void pop() {
        sta.pop_back();
    }
    
    int top() {
        return sta.back()->value;
    }
    
    int getMin() {
        return sta.back()->min;
    }
};
