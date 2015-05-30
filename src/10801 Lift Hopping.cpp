#include <cstdio>
#include <iostream>
#define MAX_LIFTS 5
#define MAX_FLOORS 100

using namespace std;

int liftCnt;
int cost[MAX_LIFTS][MAX_FLOORS];
int lift[MAX_LIFTS][MAX_FLOORS];
int speed[MAX_LIFTS];

void printCost()
{
    for (int i = 0; i < liftCnt; i++)
    {
        for (int j = 0; j < MAX_FLOORS; j++)
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
    int target;
    while (scanf("%d %d", &liftCnt, &target) == 2)
    {
        for (int i = 0; i < liftCnt; i++)
            scanf("%d", &speed[i]);

        for (int i = 0; i < liftCnt; i++)
            for (int j = 0; j < MAX_FLOORS; j++)
                lift[i][j] = 0;

        for (int i = 0; i < liftCnt; i++)
        {
            do
            {
                int j;
                scanf("%d", &j);
                lift[i][j] = 1;
            } while (cin.peek() != '\n');
        }
    }
}

/*

2 30
10 5
0 1 3 5 7 9 11 13 15 20 99
4 13 15 19 20 25 30
2 30
10 1
0 5 10 12 14 20 25 30
2 4 6 8 10 12 14 22 25 28 29
3 50
10 50 100
0 10 30 40
0 20 30
0 20 50
1 1
2
0 2 4 6 8 10

275
285
3920
IMPOSSIBLE

*/
