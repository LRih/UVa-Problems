#include <cstdio>
#include <cstring>
#include <queue>
#define MAX_GRID 50

using namespace std;

int rowCnt, colCnt;
int map[MAX_GRID][MAX_GRID];
bool visited[MAX_GRID][MAX_GRID];

int si, sj, ei, ej;
int facing;

struct agent
{
    int i, j, facing, time;
    bool canTurn;

    agent(int _i, int _j, int _facing, int _time, bool _canTurn)
    {
        i = _i;
        j = _j;
        facing = _facing;
        time = _time;
        canTurn = _canTurn;
    }
};

int turn(int curFace, int dir)
{
    if (dir == -1)
    {
        if (curFace == 0) curFace = 3;
        else curFace--;
    }
    else if (dir == 1)
    {
        if (curFace == 3) curFace = 0;
        else curFace++;
    }
    return curFace;
}

int turn2(int curFace)
{
    return turn(turn(curFace, 1), 1);
}

bool canMove(int i, int j)
{
    if (i < 1 || i >= rowCnt || j < 1 || j >= colCnt) return false;
    else return (map[i - 1][j - 1] == 0 && map[i - 1][j] == 0 &&
        map[i][j - 1] == 0 && map[i][j] == 0);
}

int getTime()
{
    int mFace[] = { 0, 1, 2, 3 };
    int mRow[] = { -1, 0, 1, 0 };
    int mCol[] = { 0, 1, 0, -1 };

    queue<agent> q;
    q.push(agent(si, sj, facing, 0, false));
    q.push(agent(si, sj, turn(facing, -1), 1, false));
    q.push(agent(si, sj, turn(facing, 1), 1, false));
    q.push(agent(si, sj, turn2(facing), 2, false));
    visited[si][sj] = true;

    while (!q.empty())
    {
        agent cur = q.front(); q.pop();

        if (cur.i == ei && cur.j == ej) return cur.time;

        // turn left/right
        if (cur.canTurn)
        {
            q.push(agent(cur.i, cur.j, turn(cur.facing, -1), cur.time + 1, false));
            q.push(agent(cur.i, cur.j, turn(cur.facing, 1), cur.time + 1, false));
        }

        // move
        for (int i = 0; i < 4; i++)
        {
            if (cur.facing == mFace[i] && canMove(cur.i + mRow[i], cur.j + mCol[i]))
            {
                if (!visited[cur.i + mRow[i]][cur.j + mCol[i]])
                {
                    q.push(agent(cur.i + mRow[i], cur.j + mCol[i], cur.facing, cur.time + 1, true));
                    visited[cur.i + mRow[i]][cur.j + mCol[i]] = true;
                }
                if (canMove(cur.i + 2 * mRow[i], cur.j +  2 * mCol[i]))
                {
                    if (!visited[cur.i + 2 * mRow[i]][cur.j + 2 * mCol[i]])
                    {
                        q.push(agent(cur.i + 2 * mRow[i], cur.j + 2 * mCol[i], cur.facing, cur.time + 1, true));
                        visited[cur.i + 2 * mRow[i]][cur.j + 2 * mCol[i]] = true;
                    }
                    if (canMove(cur.i + 3 * mRow[i], cur.j + 3 * mCol[i]))
                    {
                        if (!visited[cur.i + 3 * mRow[i]][cur.j + 3 * mCol[i]])
                        {
                            q.push(agent(cur.i + 3 * mRow[i], cur.j + 3 * mCol[i], cur.facing, cur.time + 1, true));
                            visited[cur.i + 3 * mRow[i]][cur.j + 3 * mCol[i]] = true;
                        }
                    }
                }
            }
        }
    }

    return -1;
}

int main()
{
    while (true)
    {
        scanf("%d %d", &rowCnt, &colCnt);
        if (rowCnt == 0 && colCnt == 0) break;

        for (int i = 0; i < rowCnt; i++)
        {
            for (int j = 0; j < colCnt; j++)
            {
                scanf("%d", &map[i][j]);
                visited[i][j] = false;
            }
        }

        scanf("%d %d %d %d", &si, &sj, &ei, &ej);

        char f[10];
        scanf("%s", f);

        if (strcmp(f, "north") == 0)
            facing = 0;
        else if (strcmp(f, "east") == 0)
            facing = 1;
        else if (strcmp(f, "south") == 0)
            facing = 2;
        else if (strcmp(f, "west") == 0)
            facing = 3;

        printf("%d\n", getTime());
    }
}

/*

9 10
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 1 0
7 2 2 7 south
0 0

12

*/
