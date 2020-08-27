#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main() {
    cin.sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;  
    map<long long, int> mp;
    char input[1005];
    long long mask = 0;
    for(int i = 0; i < n; i++)
        mask = mask |  1LL << i;

    int count = 0;

    while(m--)
    {
        cin >> input;
        long long tmp = 0;
        for(int i = 0; i < strlen(input); i++)
        {
            if(input[i] <= 'Z')
                tmp = tmp | 1LL << (input[i] - 'A');
            else
                tmp = tmp | 1LL << (input[i] - 'a' + 26);
        }
        if(mp.count(tmp ^ mask))
            count += mp[tmp ^ mask];
        if(mp.count(tmp))
            mp[tmp] += 1;
        else
            mp[tmp] = 1;
    }
    cout << count << endl;
}
