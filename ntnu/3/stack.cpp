#include<iostream>
#include<vector>
#include<string>
using namespace std;

int check(char a, int level)
{
    if(a == '(')
    {
        if(level > 1)
            return 2;
        else if(level == -1 || level == 1)
            return 1;
    }
    else if(a == '[')
    {
        if(level < 2)
            return 2;
        else if(level == -1 || level == 2)
            return 1;
        else if(level > 2)
            return 3;
    }
    else
    {
        if(level == -1)
            return 1;
        else if(level < 3)
            return 3;
        else
            return 2;
    }
}

int main()
{
    string input;
    cin >> input;
    int level = -1; 
    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            int status = check(input[i], level);
            if(input[i] == '(')
            {
                if(status == 1)
                    level = 1;
                else if(status == 2)
                    level = level;
                else
                    break;
                
            }
            else if(input[i] == '[')
            {
                if(status == 2)
                    break;
                else if(status == 1)
                    level = 2;
                else
                    level = level;
            }
            else if(input[i] == '{')
            {
                if(status == 1 || status == 2)
                    level = 3;
                else if(status == 3)
                    break;
            }
        }
        else if(i > 0)
        {
            cout << i << endl;
            if(input[i] == ')' && input[i-1] == '(')
            {
                input.erase(input.begin()+i-1, input.begin()+i+1);
                i = 0;
            }
            else if(input[i] == '}' && input[i-1] == '{')
            {
                input.erase(input.begin()+i-1, input.begin()+i+1);
                i = 0;
            }
            else if(input[i] == ']' && input[i-1] == '[')
            {
                input.erase(input.begin()+i-1, input.begin()+i+1);
                i = 0;
           }            
        }
    }

    if(input.size() != 0)
        cout << "0";
    else
        cout << "1";
}
