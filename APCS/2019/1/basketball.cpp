#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int home[4], away[4];
    int home_win = 0, away_win = 0;
    
    
    for(int k = 0; k < 2; k++)
    {
        int home_grade = 0, away_grade = 0;
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(i == 0)
                {
                    cin >> home[i];
                    home_grade += home[i];
                }
                else
                {
                    cin >> away[i];
                    away_grade += away[i];
                }
            }
        }
        cout << home_grade << ":" << away_grade << endl;
        if(home_grade > away_grade)
            home_win ++;
        else if(home_grade < away_grade)
            away_win ++;
    }

    if(home_win > away_win)
        cout << "Win" << endl;
    else if (home_win == away_win)
        cout << "Tie" << endl;
    else
        cout << "Lose" << endl;

}
