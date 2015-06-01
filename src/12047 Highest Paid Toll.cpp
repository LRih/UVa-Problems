#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_NODES 10000

using namespace std;

int nodeCnt;
int network[MAX_NODES][MAX_NODES];
int start, end, maxCost;

bool visited[MAX_NODES];
int maxToll;

void findPath(int node, int cost, int toll)
{
    if (node == end)
    {
        maxToll = max(maxToll, toll);
        return;
    }

    for (int i = 0; i < nodeCnt; i++)
    {
        if (visited[i] || network[node][i] == -1 || cost + network[node][i] > maxCost) continue;

        visited[i] = true;
        findPath(i, cost + network[node][i], max(toll, network[node][i]));
        visited[i] = false;
    }

    return;
}

// time limit
int main()
{
    int testCnt;
    scanf("%d", &testCnt);
    for (int c = 0; c < testCnt; c++)
    {
        int edgeCnt;
        scanf("%d %d %d %d %d", &nodeCnt, &edgeCnt, &start, &end, &maxCost);
        start--; end--;

        for (int i = 0; i < nodeCnt; i++)
            for (int j = 0; j < nodeCnt; j++)
                network[i][j] = -1;

        for (int i = 0; i < edgeCnt; i++)
        {
            int n1, n2, cost;
            scanf("%d %d %d", &n1, &n2, &cost);
            network[n1 - 1][n2 - 1] = cost;
        }

        memset(visited, 0, sizeof(visited));
        maxToll = -1;
        findPath(start, 0, 0);
        printf("%d\n", maxToll);

        // for (int i = 0; i < nodeCnt; i++)
        // {
        //     for (int j = 0; j < nodeCnt; j++)
        //         printf("%d ", network[i][j]);
        //     putchar('\n');
        // }
    }
}

/*

2
5 6 1 5 10
1 2 7
2 5 4
1 3 6
3 5 3
1 4 5
4 5 4
2 1 1 2 10
1 2 20

6
-1

*/
