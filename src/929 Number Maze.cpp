#include <cstdio>
#include <climits>
#include <queue>
#define MAX_GRID 999

using namespace std;

int rowCnt, colCnt;
int grid[MAX_GRID][MAX_GRID];
int cost[MAX_GRID][MAX_GRID];
bool visited[MAX_GRID][MAX_GRID];

struct agent
{
    int i, j, cost;

    agent()
    {
    }

    agent(int _i, int _j, int _cost)
    {
        i = _i;
        j = _j;
        cost = _cost;
    }
};

class compare
{
public:
    bool operator() (agent& a1, agent& a2)
    {
        return a1.cost >= a2.cost;
    }
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

void findPath(int si, int sj)
{
    int mRow[] = { -1, 1, 0, 0 };
    int mCol[] = { 0, 0, -1, 1 };

    priority_queue<agent, vector<agent>, compare> q;
    q.push(agent(0, 0, grid[0][0]));

    cost[0][0] = grid[0][0];

    while (!q.empty())
    {
        agent cur = q.top(); q.pop();

        if (visited[cur.i][cur.j]) continue;
        visited[cur.i][cur.j] = true;

        for (int i = 0; i < 4; i++)
        {
            int ni = cur.i + mRow[i];
            int nj = cur.j + mCol[i];

            if (ni < 0 || ni >= rowCnt || nj < 0 || nj >= colCnt)
                continue;

            if (cur.cost + grid[ni][nj] < cost[ni][nj])
            {
                q.push(agent(ni, nj, cur.cost + grid[ni][nj]));
                cost[ni][nj] = cur.cost + grid[ni][nj];
            }
        }
    }
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
                visited[i][j] = false;
            }
        }

        findPath(0, 0);
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
