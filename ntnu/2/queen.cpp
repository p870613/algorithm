#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
vector< vector<int> > ans;

bool checker(int** ar)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j ++)
        {
            if(ar[i][j] == 1)
            {
                
                for(int x = 0; x < n; x ++)
                    if(ar[x][j] == 1 && x != i)
                        return false;
                for(int y = 0; y < n; y++)
                    if(ar[i][y] == 1 && y != j)
                        return false;

                for(int x = i, y = j; x < n && y < n; x++, y++)
                    if(ar[x][y] == 1 && i != x && j != y)
                        return false;
                for(int x = i, y = j; x >= 0 && y >= 0; x--, y--)
                    if(ar[x][y] == 1 && i != x && j != y)
                        return false;
                for(int x = i, y = j; x >= 0 && y < n; x--, y++)
                    if(ar[x][y] == 1 && i != x && j != y)
                        return false;
                for(int x = i, y = j; x < n && y >= 0; x++, y--)
                    if(ar[x][y] == 1 && i != x && j != y)
                        return false;
            }
        }
    }
    return true;
}

void print(int **ar)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << ar[i][j] << " ";
        cout << endl;
    }
}

void offset(int *x, int *y, int pos)
{
    *x = pos / n;
    *y = pos % n;    
}
void DFS(int** ar, int pos, int count)
{
    if(count == m)
    {
        vector<int> tmp;
        for(int j = 0; j < n; j++)
        {
            bool ch = 0;
            for(int i = 0; i < n; i++)
            {
                if(ar[i][j] == 1)
                {
                    tmp.push_back(i);
                    ch = 1;
                    break;
                }
            }
            if(ch == 0)
                tmp.push_back(-1);
        }
        ans.push_back(tmp);
        return;
    }
    for(int i = pos + 1; i < n*n; i++)
    {
        int x, y;
        offset(&x, &y, i);
        if(ar[x][y] == 0)
        {
            ar[x][y] = 1;
            if(checker(ar))
                DFS(ar, i, count+1);
            ar[x][y] = 0;
        }
    }
}
bool cmp(vector<int> a, vector<int> b)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] < b[i])
            return true;   
        else if(a[i] > b[i])
            return false;

    }
    return false;
}

void print_ans()
{
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < n; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}

void sort()
{
     for(int i = 0; i < ans.size() ;i ++)
        for(int j = 0; j < ans.size(); j++)
            if(cmp(ans[i], ans[j]))
                ans[i].swap(ans[j]);
}

void init(int **ar)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j ++)
            ar[i][j] = 0;
}

void start_DFS(int **ar)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ar[i][j] = 1;
            DFS(ar, i*n+j, 1);
            ar[i][j] = 0;
        }
    }
}
int main()
{
    cin >> n >> m;
    int** ar = new int*[n];
    for(int i = 0; i < n; i++)
        ar[i] = new int[n];

    init(ar);

    start_DFS(ar);

    sort();
     
    print_ans();
} 
