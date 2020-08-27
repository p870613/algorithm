#include<iostream>
using namespace std;
int main()
{
    int a, b, c;
    int input1, input2, output;
    while(cin >> a >> b >> c)
    {
        /* change value to 0 or 1*/
        if(a > 0)
            input1 = 1;
        else
            input1 = 0;

        if(b > 0)
            input2 = 1;
        else
            input2 = 0;

        if(c > 0)
            output = 1;
        else
            output = 0;

        /*if flag equal to 0, there isn't any output, so output must be Impossible*/
        bool flag = 0;
        if((input1 & input2)== output)
        {
            cout << "AND" << endl;
            flag = 1;
        }
        if((input1 | input2)== output)
        {
            cout << "OR" << endl;
            flag = 1;
        }
        if((input1 ^ input2)== output)
        {
            cout << "XOR" << endl;
            flag = 1;
        }
        if(!flag)
            cout << "IMPOSSIBLE" << endl;
    }
}
