#include <iostream>
using namespace std;
long long count = 0;
int m, n;

bool check_pos(int x, int y)
{
     if(x >= 0 && x < n && y >= 0 && y < m)
         return true;
     return false;
}

int decide_dir(int **ar, int x, int y)
{
    int min = 1e8;
    int dir = 0;

    if(check_pos(x-1, y) && ar[x-1][y] != -1)//up
    {
        if(min > ar[x-1][y])
        {
            min = ar[x-1][y];
            dir = 1;
        }
    }
    if(check_pos(x+1, y) && ar[x+1][y] != -1)//down
    {
        if(min > ar[x+1][y])
        {
            min = ar[x+1][y];
            dir = 2;
        }
    }
    if(check_pos(x, y-1) && ar[x][y-1] != -1) //left 
    {
        if(min > ar[x][y-1])
        {
            min = ar[x][y-1];
            dir = 3;
        }
    }
    if(check_pos(x, y+1) && ar[x][y+1] != -1)//right
    {
        if(min > ar[x][y+1])
        {
            min = ar[x][y+1];
            dir = 4;
        }
    }
    return dir;
}

void start_move(int **ar, int x, int y)
{
    while(1)
    {
       count +=  ar[x][y];
       ar[x][y] = -1;

       int dir = decide_dir(ar, x, y);
       if(dir == 1)
           x = x - 1;
       else if(dir == 2)
           x = x + 1;
       else if(dir == 3)
           y = y - 1;
       else if(dir == 4)
           y = y + 1;
       else
           break;
    }
}

int main()
{
    cin >> n >> m;
    int **ar;
    int cur_x = 0, cur_y = 0;
    int min = 1e9;
    
    ar = new int*[n];
    for(int i = 0; i < n; i++)
        ar[i] = new int[m];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> ar[i][j];
            if(min > ar[i][j])
            {
                min = ar[i][j];
                cur_x = i;
                cur_y = j;
            }
        }
    }
    start_move(ar, cur_x, cur_y);
    cout << count  << endl;
}
