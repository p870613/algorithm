#include<iostream>
#include<unordered_map>
using namespace std;

int main()
{
    cin.sync_with_stdio(false), cin.tie(0);
    int n, len;
    string *ar;
    
    cin >> n >> len;
    ar = new string[len];
    
    for(int i = 0; i < len; i++)
        cin >> ar[i];

    unordered_map<string, int> mp;
    int ans = 0;
    int count = 0;
    for(int i = 0; i < len; i++)
    {
        if(i >= n){
            if(mp[ar[i-n]] == 1)
                count --;
            mp[ar[i-n]] --;
        }

        if(mp[ar[i]] == 0)
        {
            count ++;
            mp[ar[i]] = 1;
        }
        else
            mp[ar[i]] ++;
        if(count ==  n)
            ans ++;
    }
    cout << ans << endl;
}
