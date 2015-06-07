#include <cstdio>
#include <queue>
#define MAX_CNT 30

using namespace std;

int lvlCnt, rowCnt, colCnt;
int si, sj, sk;
char dungeon[MAX_CNT][MAX_CNT][MAX_CNT];
bool visited[MAX_CNT][MAX_CNT][MAX_CNT];

struct agent
{
    int lvl, row, col, steps;
};

bool isPassable(int lvl, int row, int col)
{
    char tile = dungeon[lvl][row][col];
    return tile == '.' || tile == 'S' || tile == 'E';
}

int findPath()
{
    int mRow[] = { -1, 1, 0, 0 };
    int mCol[] = { 0, 0, -1, 1 };

    for (int i = 0; i < lvlCnt; i++)
        for (int j = 0; j < rowCnt; j++)
            for (int k = 0; k < colCnt; k++)
                visited[i][j][k] = false;

    agent s = { si, sj, sk, 0 };

    queue<agent> q;
    q.push(s);
    visited[si][sj][sk] = true;

    while (!q.empty())
    {
        agent cur = q.front(); q.pop();

        if (dungeon[cur.lvl][cur.row][cur.col] == 'E') return cur.steps;

        // go up
        if (cur.lvl + 1 < lvlCnt && !visited[cur.lvl + 1][cur.row][cur.col] && isPassable(cur.lvl + 1, cur.row, cur.col))
        {
            agent next = { cur.lvl + 1, cur.row, cur.col, cur.steps + 1 };
            q.push(next);
            visited[cur.lvl + 1][cur.row][cur.col] = true;
        }

        // go down
        if (cur.lvl - 1 >= 0 && !visited[cur.lvl - 1][cur.row][cur.col] && isPassable(cur.lvl - 1, cur.row, cur.col))
        {
            agent next = { cur.lvl - 1, cur.row, cur.col, cur.steps + 1 };
            q.push(next);
            visited[cur.lvl - 1][cur.row][cur.col] = true;
        }

        // move
        for (int i = 0; i < 4; i ++)
        {
            int nRow = cur.row + mRow[i];
            int nCol = cur.col + mCol[i];

            if (nRow < 0 || nRow >= rowCnt || nCol < 0 || nCol >= colCnt)
                continue;

            if (!visited[cur.lvl][nRow][nCol] && isPassable(cur.lvl, nRow, nCol))
            {
                agent next = { cur.lvl, nRow, nCol, cur.steps + 1 };
                q.push(next);
                visited[cur.lvl][nRow][nCol] = true;
            }
        }
    }

    return -1;
}

int main()
{
    while (true)
    {
        scanf("%d %d %d", &lvlCnt, &rowCnt, &colCnt);
        if (lvlCnt == 0 && rowCnt == 0 && colCnt == 0) break;

        getchar();

        for (int i = 0; i < lvlCnt; i++)
        {
            for (int j = 0; j < rowCnt; j++)
            {
                for (int k = 0; k < colCnt; k++)
                {
                    dungeon[i][j][k] = getchar();
                    if (dungeon[i][j][k] == 'S')
                    {
                        si = i;
                        sj = j;
                        sk = k;
                    }
                }
                getchar();
            }
            getchar();
        }

        int path = findPath();
        if (path != -1) printf("Escaped in %d minute(s).\n", path);
        else printf("Trapped!\n");
    }
}

/*

3 4 5
S....
.###.
.##..
###.#

#####
#####
##.##
##...

#####
#####
#.###
####E

1 3 3
S##
#E#
###

0 0 0

Escaped in 11 minute(s).
Trapped!

*/
