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
    queue<pt> q;
    q.push(start);

    while (!q.empty())
    {
        pt curPt = q.front(); q.pop();

        if (curPt.i - 1 != -1)
        {
            int newCost = curPt.cost + grid[curPt.i - 1][curPt.j];
            if (cost[curPt.i - 1][curPt.j] > newCost)
            {
                pt newPt = { curPt.i - 1, curPt.j, newCost };
                q.push(newPt);
                cost[newPt.i][newPt.j] = newCost;
            }
        }
        if (curPt.i + 1 != rowCnt)
        {
            int newCost = curPt.cost + grid[curPt.i + 1][curPt.j];
            if (cost[curPt.i + 1][curPt.j] > newCost)
            {
                pt newPt = { curPt.i + 1, curPt.j, newCost };
                q.push(newPt);
                cost[newPt.i][newPt.j] = newCost;
            }
        }
        if (curPt.j - 1 != -1)
        {
            int newCost = curPt.cost + grid[curPt.i][curPt.j - 1];
            if (cost[curPt.i][curPt.j - 1] > newCost)
            {
                pt newPt = { curPt.i, curPt.j - 1, newCost };
                q.push(newPt);
                cost[newPt.i][newPt.j] = newCost;
            }
        }
        if (curPt.j + 1 != colCnt)
        {
            int newCost = curPt.cost + grid[curPt.i][curPt.j + 1];
            if (cost[curPt.i][curPt.j + 1] > newCost)
            {
                pt newPt = { curPt.i, curPt.j + 1, newCost };
                q.push(newPt);
                cost[newPt.i][newPt.j] = newCost;
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
