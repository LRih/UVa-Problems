#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    string maze;
    while (getline(cin, maze))
    {
        int times = 0;
        for (int i = 0; i < maze.length(); i++)
        {
            if (maze.at(i) >= 49 && maze.at(i) <= 57) times += maze.at(i) - 48;
            else if (maze.at(i) == '!') printf("\n");
            else
            {
                for (int j = 0; j < times; j++)
                    printf("%c", maze.at(i) == 'b' ? ' ' : maze.at(i));
                times = 0;
            }
        }
        printf("\n");
    }
}

/*

1T1b5T!1T2b1T1b2T!1T1b1T2b2T!1T3b1T1b1T!3T3b1T!1T3b1T1b1T!5T1*1T
 
11X21b1X
4X1b1X

T TTTTT
T  T TT
T T  TT
T   T T
TTT   T
T   T T
TTTTT*T
 
XX   X
XXXX X

*/
