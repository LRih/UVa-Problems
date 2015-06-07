#include <cstdio>
#include <queue>
#define MAX_NODES 100

using namespace std;

bool network[MAX_NODES][MAX_NODES];
int cost[MAX_NODES];

struct agent
{
    int node, cost;
};

double getAvg()
{
    int pairCnt = 0;
    int avg = 0;

    for (int n = 0; n < MAX_NODES; n++)
    {
        for (int i = 0; i < MAX_NODES; i++)
            cost[i] = -1;

        agent s = { n, 0 };
        queue<agent> q;
        q.push(s);
        cost[n] = 0;

        while (!q.empty())
        {
            agent cur = q.front(); q.pop();

            for (int i = 0; i < MAX_NODES; i++)
            {
                if (!network[cur.node][i] || cost[i] != -1) continue;

                agent next = { i, cur.cost + 1 };
                q.push(next);
                cost[next.node] = next.cost;
            }
        }

        for (int i = 0; i < MAX_NODES; i++)
        {
            if (cost[i] > 0)
            {
                pairCnt++;
                avg += cost[i];
            }
        }
    }

    return avg / (double)pairCnt;
}

int main()
{
    int test = 1;
    while (true)
    {
        for (int i = 0; i < MAX_NODES; i++)
            for (int j = 0; j < MAX_NODES; j++)
                network[i][j] = false;

        int a, b;
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) break;
        network[a - 1][b - 1] = true;

        while (true)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            if (a == 0 && b == 0) break;
            network[a - 1][b - 1] = true;
        }

        printf("Case %d: average length between pages = %.3f clicks\n", test, getAvg());

        test++;
    }
}

/*

1 2 2 4 1 3 3 1 4 3 0 0
1 2 1 4 4 2 2 7 7 1 0 0
0 0

Case 1: average length between pages = 1.833 clicks
Case 2: average length between pages = 1.750 clicks

*/
