#include<iostream>
#include<algorithm>
using namespace std;
class box{
public:
    int w;
    int f;
};

bool cmp(class box a, class box b)
{
    return a.w*b.f < b.w*a.f;
}
int main()
{
   int n;
   while(cin >> n)
   {
       class box *ar = new class box[n];
       for(int i = 0; i < n; i++)
           cin >> ar[i].w;

        for(int i = 0; i < n; i++)
           cin >> ar[i].f;

       sort(ar, ar+n, cmp);

       int sum = 0, ans = 0;
       for(int i = 0; i < n-1; i++)
       {
           sum = sum + ar[i].w;
           ans = ans + sum * ar[i+1].f;
       }
       cout << ans << endl;
   }
}
