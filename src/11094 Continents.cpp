#include <cstdio>
#include <queue>
#include <algorithm>
#include <iostream>
#define MAX_GRID 20

using namespace std;

int rowCnt, colCnt;
char map[MAX_GRID][MAX_GRID];
bool marked[MAX_GRID][MAX_GRID];
char land;

struct agent
{
    int i, j;
};

int getLandSize(int si, int sj)
{
    int size = 1;

    int mRow[] = { -1, 1, 0, 0 };
    int mCol[] = { 0, 0, -1, 1 };

    agent a = { si, sj };
    queue<agent> q;
    q.push(a);
    marked[si][sj] = true;

    while (!q.empty())
    {
        agent cur = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ni = cur.i + mRow[i];
            int nj = cur.j + mCol[i];

            if (nj < 0) nj = colCnt - 1;
            else if (nj >= colCnt) nj = 0;

            if (ni < 0 || ni >= rowCnt) continue;
            if (map[ni][nj] != land || marked[ni][nj]) continue;

            agent next = { ni, nj };
            q.push(next);
            marked[ni][nj] = true;
            size++;
        }
    }

    return size;
}

int getMaxLandSize()
{
    int maxSize = 0;
    for (int i = 0; i < rowCnt; i++)
        for (int j = 0; j < colCnt; j++)
            if (map[i][j] == land && !marked[i][j])
                maxSize = max(getLandSize(i, j), maxSize);
    return maxSize;
}

int main()
{
    while (true)
    {
        scanf("%d %d\n", &rowCnt, &colCnt);
        for (int i = 0; i < rowCnt; i++)
        {
            for (int j = 0; j < colCnt; j++)
                scanf("%c", &map[i][j]);
            getchar();
        }

        for (int i = 0; i < rowCnt; i++)
            for (int j = 0; j < colCnt; j++)
                marked[i][j] = false;

        int si, sj;
        scanf("%d %d", &si, &sj);
        land = map[si][sj];
        getLandSize(si, sj);

        printf("%d\n", getMaxLandSize());

        getchar();
        getchar();
        if (cin.peek() == EOF) break;

    }
}

/*

5 5
wwwww
wwllw
wwwww
wllww
wwwww
1 3

2

*/
