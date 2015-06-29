#include <cstdio>
#include <queue>
#define MAX_GRID 100

using namespace std;

int gridSize;
char grid[MAX_GRID][MAX_GRID];

struct agent
{
    int i, j;
};

void markShip(int si, int sj)
{
    int mRow[] = { 0, 0, -1, 1 };
    int mCol[] = { -1, 1, 0, 0 };

    agent a = { si, sj };
    queue<agent> q;
    q.push(a);
    grid[si][sj] = 'L';

    while (!q.empty())
    {
        agent cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ni = cur.i + mRow[i];
            int nj = cur.j + mCol[i];

            if (ni < 0 || ni >= gridSize || nj < 0 || nj >= gridSize) continue;
            if (grid[ni][nj] != 'x' && grid[ni][nj] != '@') continue;

            agent next = { ni, nj };
            q.push(next);
            grid[ni][nj] = 'L';
        }
    }
}

int countShips()
{
    int count = 0;
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if (grid[i][j] == 'x')
            {
                markShip(i, j);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int tests;
    scanf("%d", &tests);

    for (int t = 1; t <= tests; t++)
    {
        scanf("%d\n", &gridSize);
        for (int i = 0; i < gridSize; i++)
        {
            for (int j = 0; j < gridSize; j++)
                scanf("%c", &grid[i][j]);
            getchar();
        }

        printf("Case %d: %d\n", t, countShips());
    }

}

/*

2
4
x...
..x.
@.@.
....
2
..
x.

Case 1: 2
Case 2: 1

*/
