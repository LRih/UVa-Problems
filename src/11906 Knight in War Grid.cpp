#include <cstdio>
#include <stack>
#define MAX_GRID 100
#define CAN_VISIT 1
#define VISITED 2
#define WATER 9

using namespace std;

int rowCnt, colCnt;
int jump1, jump2;
int grid[MAX_GRID][MAX_GRID];
int evenCnt, oddCnt;

struct agent
{
    int row, col;
};

bool canJump(int sr, int sc, int dr, int dc)
{
    int nrow = sr + dr;
    int ncol = sc + dc;

    if (nrow < 0 || nrow >= rowCnt || ncol < 0 || ncol >= colCnt) return false;

    bool leftAccess = true;
    bool rightAccess = true;

    int crow = sr;
    int ccol = sc;
    int dir = (nrow - sr > 0 ? 1 : -1);
    while (crow != nrow)
    {
        if (grid[crow][ccol] == WATER) leftAccess = false;
        crow += dir;
    }
    if (grid[crow][ccol] == WATER) leftAccess = false;
    dir = (ncol - sc > 0 ? 1 : -1);
    while (ccol != ncol)
    {
        if (grid[crow][ccol] == WATER) leftAccess = false;
        ccol += dir;
    }
    if (grid[crow][ccol] == WATER) leftAccess = false;

    crow = sr;
    ccol = sc;
    dir = (ncol - sc > 0 ? 1 : -1);
    while (ccol != ncol)
    {
        if (grid[crow][ccol] == WATER) rightAccess = false;
        ccol += dir;
    }
    if (grid[crow][ccol] == WATER) rightAccess = false;
    dir = (nrow - sr > 0 ? 1 : -1);
    while (crow != nrow)
    {
        if (grid[crow][ccol] == WATER) rightAccess = false;
        crow += dir;
    }
    if (grid[crow][ccol] == WATER) rightAccess = false;

    return leftAccess || rightAccess;
}

void check()
{
    int jumpRow[] = { -jump1, jump1, -jump2, jump2, -jump1, jump1, -jump2, jump2 };
    int jumpCol[] = { -jump2, jump2, -jump1, jump1, jump2, -jump2, jump1, -jump1 };

    agent a = { 0, 0 };
    stack<agent> s;
    s.push(a);

    while (!s.empty())
    {
        agent cur = s.top(); s.pop();

        if (grid[cur.row][cur.col] == VISITED) continue;
        grid[cur.row][cur.col] = VISITED;

        int jumps = 0;
        for (int i = 0; i < 8; i++)
        {
            if (canJump(cur.row, cur.col, jumpRow[i], jumpCol[i]))
            {
                jumps++;
                agent next = { cur.row + jumpRow[i], cur.col + jumpCol[i] };
                if (grid[next.row][next.col] != VISITED)
                {
                    s.push(next);
                    grid[next.row][next.col] = CAN_VISIT;
                }
            }
        }
        if (jumps % 2 == 0) evenCnt++;
        else oddCnt++;
    }
}

// wrong answer
int main()
{
    int tests;
    scanf ("%d", &tests);

    for (int t = 0; t < tests; t++)
    {
        evenCnt = 0; oddCnt = 0;
        scanf("%d %d %d %d", &rowCnt, &colCnt, &jump1, &jump2);

        for (int i = 0; i < rowCnt; i++)
            for (int j = 0; j < colCnt; j++)
                grid[i][j] = 0;

        int waterCnt;
        scanf("%d", &waterCnt);

        for (int i = 0; i < waterCnt; i++)
        {
            int row, col;
            scanf("%d %d", &row, &col);
            grid[row][col] = WATER;
        }

        check();
        printf("Case %d: %d %d\n", t + 1, evenCnt, oddCnt);
    }
}

/*

2
3 3 2 1
0
4 4 1 2
2
3 3
1 1

Case 1: 8 0
Case 2: 4 10

*/
