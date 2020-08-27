#include<iostream>
using namespace std;

class TREE{
public:
    void link_child(int m, int *ar, class TREE *tree);
    void link_root(int i,class TREE *tree);
    bool isnull();
    void find_h(class TREE *cur, int cur_h);
    int get_h();
private:
    class TREE *root = NULL;
    class TREE *(*child);
    int h = 0;
};

void TREE::link_child(int m, int *ar, class TREE *tree)
{
    child = new class TREE*[m];
    for(int i = 0; i < m; i++)
        this->child[i] = &(tree[ar[i]]);

}

void TREE::link_root(int i,class TREE *tree)
{
    this->root = &(tree[i]);
}

void TREE::find_h(class TREE *cur, int cur_h)
{
    if(cur->root != NULL)
    {
        if(cur -> h < cur_h)
            cur -> h = cur_h;
        find_h(cur->root, cur_h+1);
    }
    else
    {
        if(cur -> h < cur_h)
            cur -> h = cur_h;
        return;
    }


}
bool TREE::isnull()
{
    if(this->root == NULL)
        return true;
    return false;
}

int TREE::get_h()
{
    return this->h;
}

int main()
{
    int n;
    while(cin >> n)
    {
        class TREE *tree = new class TREE[n];
        for(int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            int *ar = new int[m];
            for(int j = 0; j < m; j++)
            {
                cin >> ar[j];
                ar[j] --;
                tree[ar[j]].link_root(i, tree);
            }
            tree[i].link_child(m, ar, tree);
        }
        for(int i = 0; i < n; i++)
            if(tree[i].isnull())
                cout << i+1 << endl;

        for(int i = 0; i < n; i++)
            tree[i].find_h(&(tree[i]), 0);

        int sum = 0;
        for(int i = 0; i < n; i++)
           sum += tree[i].get_h();

        cout << sum << endl;
        delete tree;

    }
}
