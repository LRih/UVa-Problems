#include <cstdio>
#include <climits>
#include <queue>
#include <iostream>
#define MAX_LIFTS 5
#define MAX_FLOORS 100
#define TRANSFER_TIME 60

using namespace std;

int liftCnt;
int cost[MAX_LIFTS][MAX_FLOORS];
int lift[MAX_LIFTS][MAX_FLOORS];
int slowness[MAX_LIFTS];

struct agent
{
    int lift, floor, time;
};

void printCost()
{
    for (int i = 0; i < liftCnt; i++)
    {
        for (int j = 0; j < MAX_FLOORS; j++)
            printf("%d ", cost[i][j]);
        putchar('\n');
    }
}

// bfs
int findPath(int target)
{
    queue<agent> q;

    // try all available lifts from floor 0
    for (int i = 0; i < liftCnt; i++)
    {
        if (lift[i][0])
        {
            agent start = { i, 0, 0 };
            q.push(start);
            cost[start.lift][start.floor] = start.time;
        }
    }

    while (!q.empty())
    {
        agent cur = q.front(); q.pop();

        // go down current lift
        if (cur.floor - 1 != -1 && cur.time + slowness[cur.lift] < cost[cur.lift][cur.floor - 1])
        {
            agent next = { cur.lift, cur.floor - 1, cur.time + slowness[cur.lift] };
            q.push(next);
            cost[next.lift][next.floor] = next.time;
        }

        // go up current lift
        if (cur.floor + 1 != MAX_FLOORS && cur.time + slowness[cur.lift] < cost[cur.lift][cur.floor + 1])
        {
            agent next = { cur.lift, cur.floor + 1, cur.time + slowness[cur.lift] };
            q.push(next);
            cost[next.lift][next.floor] = next.time;
        }

        // transfer lift
        for (int i = 0; i < liftCnt; i++)
        {
            bool canTransfer = lift[cur.lift][cur.floor] && lift[i][cur.floor];
            if (i != cur.lift && canTransfer && cur.time + TRANSFER_TIME < cost[i][cur.floor])
            {
                agent next = { i, cur.floor, cur.time + TRANSFER_TIME };
                q.push(next);
                cost[next.lift][next.floor] = next.time;
            }
        }
    }

    int min = INT_MAX;
    for (int i = 0; i < liftCnt; i++)
        if (lift[i][target] && cost[i][target] < min) min = cost[i][target];
    return min;
}

int main()
{
    int target;
    while (scanf("%d %d", &liftCnt, &target) == 2)
    {
        for (int i = 0; i < liftCnt; i++)
            scanf("%d", &slowness[i]);

        for (int i = 0; i < liftCnt; i++)
        {
            for (int j = 0; j < MAX_FLOORS; j++)
            {
                cost[i][j] = INT_MAX;
                lift[i][j] = false;
            }
        }

        for (int i = 0; i < liftCnt; i++)
        {
            do
            {
                int j;
                scanf("%d", &j);
                lift[i][j] = true;
            } while (cin.peek() != '\n');
        }


        int time = findPath(target);
        if (time == INT_MAX) printf("IMPOSSIBLE\n");
        else printf("%d\n", time);
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
