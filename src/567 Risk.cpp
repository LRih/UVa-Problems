#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX_NODES 20

using namespace std;

struct agent
{
    int node, cost;
};

bool graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

int getMin(int s, int e)
{
    agent a = { s, 0 };

    queue<agent> q;
    q.push(a);

    while (!q.empty())
    {
        agent cur = q.front(); q.pop();

        if (cur.node == e) return cur.cost;

        if (visited[cur.node]) continue;
        visited[cur.node] = true;

        for (int i = 0; i < MAX_NODES; i++)
        {
            if (!graph[cur.node][i]) continue;

            agent next = { i, cur.cost + 1 };
            q.push(next);
        }
    }

    return -1;
}

int main()
{
    int testCnt = 1;

    while (true)
    {
        for (int i = 0; i < MAX_NODES; i++)
            for (int j = 0; j < MAX_NODES; j++)
                graph[i][j] = false;

        for (int i = 0; i < MAX_NODES - 1; i++)
        {
            int edgeCnt;
            if (scanf("%d", &edgeCnt) != 1) return EXIT_SUCCESS;

            for (int j = 0; j < edgeCnt; j++)
            {
                int node;
                scanf("%d", &node);

                graph[i][node - 1] = true;
                graph[node - 1][i] = true;
            }
        }

        printf("Test Set #%d\n", testCnt);

        int pairCnt;
        scanf("%d", &pairCnt);

        for (int i = 0; i < pairCnt; i++)
        {
            int s, e;
            scanf("%d %d", &s, &e);

            memset(visited, 0, sizeof(visited));
            printf("%2d to %2d: %d\n", s, e, getMin(s - 1, e - 1));
        }

        printf("\n");

        testCnt++;
    }
}

/*

1 3
2 3 4
3 4 5 6
1 6
1 7
2 12 13
1 8
2 9 10
1 11
1 11
2 12 17
1 14
2 14 15
2 15 16
1 16
1 19
2 18 19
1 20
1 20
5
1 20
2 9
19 5
18 19
16 20
4 2 3 5 6
1 4
3 4 10 5
5 10 11 12 19 18
2 6 7
2 7 8
2 9 10
1 9
1 10
2 11 14
3 12 13 14
3 18 17 13
4 14 15 16 17
0
0
0
2 18 20
1 19
1 20
6
1 20
8 20
15 16
11 4
7 13
2 16

Test Set #1
 1 to 20: 7
 2 to  9: 5
19 to  5: 6
18 to 19: 2
16 to 20: 2

Test Set #2
 1 to 20: 4
 8 to 20: 5
15 to 16: 2
11 to  4: 1
 7 to 13: 3
 2 to 16: 4

*/