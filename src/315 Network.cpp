#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define MAX_NODES 100

using namespace std;

int nodeCnt;
bool network[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

bool isConnected(int down)
{
    memset(visited, 0, sizeof(visited));
    visited[down] = true;

    queue<int> q;
    q.push((down + 1) % nodeCnt);
    visited[(down + 1) % nodeCnt] = true;

    while (!q.empty())
    {
        int cur = q.front(); q.pop();

        for (int i = 0; i < nodeCnt; i++)
        {
            if (network[cur][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    for (int i = 0; i < nodeCnt; i++)
        if (!visited[i]) return false;
    return true;
}

int findCrits()
{
    int crits = 0;
    for (int i = 0; i < nodeCnt; i++)
        if (!isConnected(i)) crits++;
    return crits;
}

int main()
{
    while (true)
    {
        scanf("%d", &nodeCnt);
        if (nodeCnt == 0) break;

        for (int i = 0; i < nodeCnt; i++)
            for (int j = 0; j < nodeCnt; j++)
                network[i][j] = false;

        while (true)
        {
            int n1, n2;
            scanf("%d", &n1);
            if (n1 == 0)
            {
                printf("%d\n", findCrits());
                break;
            }
            else
            {
                while (cin.peek() != '\n')
                {
                    scanf("%d", &n2);
                    network[n1 - 1][n2 - 1] = network[n2 - 1][n1 - 1] = true;
                }
            }
        }
    }
}

/*

5
5 1 2 3 4
0
6
2 1 3
5 4 6 2
0
0

1
2

*/
