#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX_NODES 100

using namespace std;

int nodeCnt, start, end;
bool network[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

struct agent
{
    int node, time;
};

int getDist(int s, int e)
{
    memset(visited, 0, sizeof(visited));

    agent a = { s, 0 };
    queue<agent> q;
    q.push(a);

    while (!q.empty())
    {
        agent cur = q.front(); q.pop();

        if (cur.node == e)
            return cur.time;

        for (int i = 0; i < nodeCnt; i++)
        {
            if (network[cur.node][i] && !visited[i])
            {
                agent next = { i, cur.time + 1 };
                q.push(next);
                visited[i] = true;
            }
        }
    }

    return -1;
}

int getMin()
{
    int result = -1;

    for (int n = 0; n < nodeCnt; n++)
        result = max(result, getDist(start, n) + getDist(n, end));

    return result;
}

int main()
{
    int tests;
    scanf("%d", &tests);

    for (int t = 0; t < tests; t++)
    {
        int edgeCnt;
        scanf("%d %d", &nodeCnt, &edgeCnt);

        for (int i = 0; i < nodeCnt; i++)
            for (int j = 0; j < nodeCnt; j++)
                network[i][j] = false;

        for (int i = 0; i < edgeCnt; i++)
        {
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            network[n1][n2] = network[n2][n1] = true;
        }

        scanf("%d %d", &start, &end);

        printf("Case %d: %d\n", t + 1, getMin());
    }
}

/*

2
4
3
0 1
2 1
1 3
0 3
2
1
0 1
1 0

Case 1: 4
Case 2: 1

*/
