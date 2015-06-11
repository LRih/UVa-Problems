#include <cstdio>
#define MAX_GRID 100

using namespace std;

int si, sj, facing;
int rowCnt, colCnt, moveCnt;
char map[MAX_GRID][MAX_GRID];
int collected;

void turn(int dir)
{
    if (dir == -1)
    {
        if (facing == 0) facing = 3;
        else facing--;
    }
    else if (dir == 1)
    {
        if (facing == 3) facing = 0;
        else facing++;
    }
}

void move(char cmd)
{
    if (cmd == 'D') turn(1);
    else if (cmd == 'E') turn(-1);
    else if (cmd == 'F')
    {
        int ni = si;
        int nj = sj;
        switch (facing)
        {
            case 0: ni = si - 1; break;
            case 1: nj = sj + 1; break;
            case 2: ni = si + 1; break;
            case 3: nj = sj - 1; break;
        }
        if (ni >= 0 && ni < rowCnt && nj >= 0 && nj < colCnt && map[ni][nj] != '#')
        {
            si = ni; sj = nj;
            if (map[ni][nj] == '*')
            {
                map[ni][nj] = '.';
                collected++;
            }
        }
    }
}

int main()
{
    while (true)
    {
        scanf("%d %d %d", &rowCnt, &colCnt, &moveCnt);
        if (rowCnt == 0 && colCnt == 0 && moveCnt == 0) break;

        getchar();
        for (int i = 0; i < rowCnt; i++)
        {
            for (int j = 0; j < colCnt; j++)
            {
                scanf("%c", &map[i][j]);
                if (map[i][j] == 'N' || map[i][j] == 'L' || map[i][j] == 'S' || map[i][j] == 'O')
                {
                    switch(map[i][j])
                    {
                        case 'N': facing = 0; break;
                        case 'L': facing = 1; break;
                        case 'S': facing = 2; break;
                        case 'O': facing = 3; break;
                    }
                    si = i; sj = j;
                    map[i][j] = '.';
                }
            }
            getchar();
        }

        collected = 0;
        for (int i = 0; i < moveCnt; i++)
        {
            char cmd;
            scanf("%c", &cmd);
            move(cmd);
        }
        getchar();

        printf("%d\n", collected);
    }
}

/*

3 3 2
***
*N*
***
DE
4 4 5
...#
*#O.
*.*.
*.#.
FFEFF
10 10 20
....*.....
.......*..
.....*....
..*.#.....
...#N.*..*
...*......
..........
..........
..........
..........
FDFFFFFFEEFFFFFFEFDF
0 0 0

0
1
3

*/
