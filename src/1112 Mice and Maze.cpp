#include <cstdio>
#include <cstring>
#include <queue>
#define MAX_CELLS 100

using namespace std;

int cellCnt, end, timer;
int maze[MAX_CELLS][MAX_CELLS];
bool visited[MAX_CELLS];

struct agent
{
    int id, time;

    agent(int _id, int _time)
    {
        id = _id;
        time = _time;
    }
};

class compare
{
public:
    bool operator() (agent& a1, agent& a2)
    {
        return a1.time >= a2.time;
    }
};

bool isEscape(int start)
{
    memset(visited, 0, sizeof(visited));

    priority_queue<agent, vector<agent>, compare> q;
    q.push(agent(start, 0));

    while (!q.empty())
    {
        agent cur = q.top(); q.pop();

        if (cur.id == end) return true;

        if (visited[cur.id]) continue;
        visited[cur.id] = true;

        for (int i = 0; i < cellCnt; i++)
        {
            if (maze[cur.id][i] != -1 && cur.time + maze[cur.id][i] <= timer)
                q.push(agent(i, cur.time + maze[cur.id][i]));
        }
    }

    return false;
}

int getMice()
{
    int count = 0;
    for (int t = 0; t < cellCnt; t++)
        if (isEscape(t)) count++;
    return count;
}

int main()
{
    int tests;
    scanf("%d", &tests);

    for (int t = 0; t < tests; t++)
    {
        int edgeCnt;
        scanf("%d %d %d %d", &cellCnt, &end, &timer, &edgeCnt);
        end--;

        for (int i = 0; i < cellCnt; i++)
            for (int j = 0; j < cellCnt; j++)
                maze[i][j] = -1;

        for (int i = 0; i < edgeCnt; i++)
        {
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            scanf("%d", &maze[n1 - 1][n2 - 1]);
        }

        if (t > 0) putchar('\n');
        printf("%d\n", getMice());
    }
}

/*

1

4
2
1
8
1 2 1
1 3 1
2 1 1
2 4 1
3 1 1
3 4 1
4 2 1
4 3 1

3

*/
