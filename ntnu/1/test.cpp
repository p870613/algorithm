#include<iostream>
using namespace std;

struct Node{
    int val;
    struct Node* next;
};

void init(Node *n, int val)
{
    n -> val = val;
    n -> next = NULL;
}

void travel(Node *head)
{
    Node **cur = &head;
    if((*cur) -> next)
        *cur = (*cur) -> next;
    else
    {
        cout << "-1";
        return;
    }

    while(*cur)
    {
        cout << (*cur) -> val << " ";
        *cur = (*cur) -> next;
    }
}
void add_chain(int* input, Node **head, int len)
{
    Node *cur = *head;
    for(int i = len-1 ; i >= 0; i--)
    {
        Node *new_node = new Node();
        init(new_node, input[i]);
        if(cur != NULL && new_node != NULL)
        {
            cur -> next = new_node;
            cur = new_node;
        }
        else
        {
            delete new_node;
            break;
        }
    }
}
void build_list(Node *list[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        int input[m];
        for(int j = 0; j < m; j++)
            cin >> input[j];

        list[i] = new Node();
        init(list[i], i);
        add_chain(input, &list[i], m);
    }
}

bool sort_compare(Node* std, Node* n)
{
    Node** cur_std = &std;
    Node** cur_n = &n;
    if((*cur_std) -> next == NULL && (*cur_n) -> next != NULL)
        return false;
    if((*cur_std) -> next != NULL && (*cur_n) -> next == NULL)
        return true;
   
    if((*cur_std) -> next)
        *cur_std = (*cur_std) -> next;
    if((*cur_n) -> next)
        *cur_n = (*cur_n) -> next;
       
    while(*cur_std != NULL && *cur_n != NULL)
    {
        if((*cur_n) -> val <= (*cur_std) -> val)
            return true;
        else if((*cur_n) -> val > (*cur_std) -> val)
            return false;
       
        *cur_std = (*cur_std) -> next;
        *cur_n = (*cur_n) -> next;
        
    }
    if(*cur_std == NULL && *cur_n != NULL)
        return true;
    return false;
}

void swap(Node* list[], int a, int b)
{
    Node* tmp = list[a];
    list[a] = list[b];
    list[b] = tmp;
}
void sort_list(Node* list[], int low, int high)
{   
    if((high - low) <= 1)
        return;
    
    Node* std = list[high-1];
    int less = low;
    for(int i = low; i < high; i++)
    {
        if(sort_compare(std, list[i]))
        {    
            swap(list, i, less);
            less ++;
        }
    }
    sort_list(list, low, less-1);
    sort_list(list, less, high);
}

void print_list(Node* list[], int n)
{
    for(int i = 0; i < n; i++)
    {
        travel(list[i]);
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    Node *list[n];
     
    build_list(list, n);

    sort_list(list, 0, n);

    print_list(list, n);
}
