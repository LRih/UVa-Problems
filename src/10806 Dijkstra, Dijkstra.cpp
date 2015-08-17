#include <cstdio>
#include <climits>
#include <cstring>
#include <queue>
#define MAX_NODES 100

using namespace std;

struct agent
{
    int node, cost;
};

class compare
{
public:
    bool operator() (agent& a1, agent& a2)
    {
        return a1.cost >= a2.cost;
    }
};

int nodeCnt;
int nodes[MAX_NODES][MAX_NODES];
int cost[MAX_NODES];
int path[MAX_NODES];
bool visited[MAX_NODES];

int getMin(int s, int e)
{
    agent a = { s, 0 };
    priority_queue<agent, vector<agent>, compare> q;
    q.push(a);

    while (!q.empty())
    {
        agent cur = q.top(); q.pop();

        if (visited[cur.node]) continue;
        visited[cur.node] = true;

        for (int i = 0; i < nodeCnt; i++)
        {
            if (visited[i] || nodes[cur.node][i] == -1) continue;

            if (cur.cost + nodes[cur.node][i] < cost[i])
            {
                path[i] = cur.node;
                cost[i] = cur.cost + nodes[cur.node][i];

                agent next = { i, cost[i] };
                q.push(next);
            }
        }
    }

    return cost[e];
}

// unfinished
int main()
{
    while (true)
    {
        scanf("%d", &nodeCnt);
        if (nodeCnt == 0) break;

        int edgeCnt;
        scanf("%d", &edgeCnt);

        for (int i = 0; i < nodeCnt; i++)
        {
            for (int j = 0; j < nodeCnt; j++)
                nodes[i][j] = -1;
            cost[i] = INT_MAX;
            path[i] = -1;
            visited[i] = false;
        }

        for (int i = 0; i < edgeCnt; i++)
        {
            int n1, n2, cost;
            scanf("%d %d %d", &n1, &n2, &cost);
            nodes[n1 - 1][n2 - 1] = cost;
            nodes[n2 - 1][n1 - 1] = cost;
        }

        int path1 = getMin(0, nodeCnt - 1);

        for (int i = 0; i < nodeCnt; i++)
            cost[i] = INT_MAX;
        memset(visited, 0, sizeof(visited));

        /* remove path taken */
        for (int i = nodeCnt - 1; path[i] != -1; i = path[i])
        {
            nodes[i][path[i]] = -1;
            nodes[path[i]][i] = -1;
        }

        int path2 = getMin(0, nodeCnt - 1);

        if (path1 == INT_MAX || path2 == INT_MAX) printf("Back to jail\n");
        else printf("%d\n", path1 + path2);
    }
}

/*

2
1
1 2 999
3
3
1 3 10
2 1 20
3 2 50
9
12
1 2 10
1 3 10
1 4 10
2 5 10
3 5 10
4 5 10
5 7 10
6 7 10
7 8 10
6 9 10
7 9 10
8 9 10
0

Back to jail
80
Back to jail

6
8
1 2 1
2 3 1
3 6 1
1 4 100
4 5 100
5 6 100
1 3 10
2 6 10

22

*/
