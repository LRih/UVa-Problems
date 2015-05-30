#include <cstdio>
#include <queue>
#define MAX_GRID 1000

using namespace std;

struct pt
{
    int i, j;
};

// find shortest path using BFS
int findPath(int grid[][MAX_GRID], int rowCnt, int colCnt, pt start, pt end)
{
    int path[MAX_GRID][MAX_GRID];
    grid[start.i][start.j] = 1;

    queue<pt> q;
    q.push(start);

    while (!q.empty())
    {
        pt curPt = q.front();
        q.pop();

        if (curPt.i - 1 != -1 && grid[curPt.i - 1][curPt.j] == 0)
        {
            pt newPt = { curPt.i - 1, curPt.j };
            q.push(newPt);
            grid[newPt.i][newPt.j] = 2;
        }
        if (curPt.i + 1 != rowCnt && grid[curPt.i + 1][curPt.j] == 0)
        {
            pt newPt = { curPt.i + 1, curPt.j };
            q.push(newPt);
            grid[newPt.i][newPt.j] = 4;
        }
        if (curPt.j - 1 != -1 && grid[curPt.i][curPt.j - 1] == 0)
        {
            pt newPt = { curPt.i, curPt.j - 1 };
            q.push(newPt);
            grid[newPt.i][newPt.j] = 1;
        }
        if (curPt.j + 1 != colCnt && grid[curPt.i][curPt.j + 1] == 0)
        {
            pt newPt = { curPt.i, curPt.j + 1 };
            q.push(newPt);
            grid[newPt.i][newPt.j] = 3;
        }
    }

    int dist = 0;
    if (grid[end.i][end.j] != 0)
    {
        int x = end.i, y = end.j;
        while (x != start.i || y != start.j)
        {
            switch (grid[x][y])
            {
                case 1: y++; break;
                case 2: x++; break;
                case 3: y--; break;
                case 4: x--; break;
            }
            dist++;
        }
    }
    return dist;
}

int main()
{
    while (true)
    {
        int grid[MAX_GRID][MAX_GRID];
        int rowCnt, colCnt;
        scanf("%d %d", &rowCnt, &colCnt);
        if (rowCnt == 0 && colCnt == 0) break;

        for (int i = 0; i < rowCnt; i++)
            for (int j = 0; j < colCnt; j++)
                grid[i][j] = 0;

        int rowBombsCnt;
        scanf("%d", &rowBombsCnt);
        for (int i = 0; i < rowBombsCnt; i++)
        {
            int row, colBombsCnt;
            scanf("%d %d", &row, &colBombsCnt);
            for (int j = 0; j < colBombsCnt; j++)
            {
                int col;
                scanf("%d", &col);
                grid[row][col] = 7;
            }
        }

        pt start, end;
        scanf("%d %d %d %d", &start.i, &start.j, &end.i, &end.j);
        printf("%d\n", findPath(grid, rowCnt, colCnt, start, end));
    }
}

/*

10 10
9
0 1 2
1 1 2
2 2 2 9
3 2 1 7
5 3 3 6 9
6 4 0 1 2 7
7 3 0 3 8
8 2 7 9
9 3 2 3 4
0 0
9 9
0 0

18

*/
