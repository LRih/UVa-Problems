#include <cstdio>
#include <climits>
#include <queue>
#define MAX_GRID 999

using namespace std;

int rowCnt, colCnt;
int grid[MAX_GRID][MAX_GRID];
int cost[MAX_GRID][MAX_GRID];

struct pt
{
    int i, j, cost;
};

void printCost()
{
    putchar('\n');
    for (int i = 0; i < rowCnt; i++)
    {
        for (int j = 0; j < colCnt; j++)
            printf("%d ", cost[i][j]);
        putchar('\n');
    }
}

void findPath(pt start)
{
    int mRow[] = { -1, 1, 0, 0 };
    int mCol[] = { 0, 0, -1, 1 };

    queue<pt> q;
    q.push(start);

    while (!q.empty())
    {
        pt curPt = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            if (curPt.i + mRow[i] != -1 && curPt.i + mRow[i] != rowCnt &&
                curPt.j + mCol[i] != -1 && curPt.j + mCol[i] != colCnt)
            {
                pt newPt = { curPt.i + mRow[i], curPt.j + mCol[i], 0 };
                int newCost = curPt.cost + grid[newPt.i][newPt.j];
                if (cost[newPt.i][newPt.j] > newCost)
                {
                    newPt.cost = newCost;
                    q.push(newPt);
                    cost[newPt.i][newPt.j] = newCost;
                }
            }
        }
    }

    if (rowCnt == 1 && colCnt == 1)
        cost[0][0] = grid[0][0];
}

int main()
{
    int cnt;
    scanf("%d", &cnt);
    for (int c = 0; c < cnt; c++)
    {
        scanf("%d %d", &rowCnt, &colCnt);
        for (int i = 0; i < rowCnt; i++)
        {
            for (int j = 0; j < colCnt; j++)
            {
                scanf("%d", &grid[i][j]);
                cost[i][j] = INT_MAX;
            }
        }

        pt start = { 0, 0, grid[0][0] };
        findPath(start);
        printf("%d\n", cost[rowCnt - 1][colCnt - 1]);
    }
}

/*

2
4
5
0 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
1
6
0 1 2 3 4 5

24
15

*/
