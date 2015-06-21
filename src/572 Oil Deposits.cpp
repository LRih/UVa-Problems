#include <cstdio>
#include <queue>
#define MAX_GRID 100

using namespace std;

int rowCnt, colCnt;
char grid[MAX_GRID][MAX_GRID];

struct agent
{
    int i, j;
};

void markOil(int si, int sj)
{
    int mRow[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
    int mCol[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

    agent a = { si, sj };
    queue<agent> q;
    q.push(a);
    grid[si][sj] = '.';

    while (!q.empty())
    {
        agent cur = q.front(); q.pop();

        for (int i = 0; i < 8; i++)
        {
            int ni = cur.i + mRow[i];
            int nj = cur.j + mCol[i];

            if (ni < 0 || ni >= rowCnt || nj < 0 || nj >= colCnt) continue;
            if (grid[ni][nj] != '@') continue;

            agent next = { ni, nj };
            q.push(next);
            grid[ni][nj] = '.';
        }
    }
}

int main()
{
    while (true)
    {
        scanf("%d %d\n", &rowCnt, &colCnt);
        if (rowCnt == 0 && colCnt == 0) break;

        for (int i = 0; i < rowCnt; i++)
        {
            for (int j = 0; j < colCnt; j++)
                scanf("%c", &grid[i][j]);
            getchar();
        }

        int count = 0;
        for (int i = 0; i < rowCnt; i++)
        {
            for (int j = 0; j < colCnt; j++)
            {
                if (grid[i][j] == '@')
                {
                    markOil(i, j);
                    count++;
                }
            }
        }

        printf("%d\n", count);
    }
}

/*

1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0

0
1
2
2

*/
