#include <cstdio>
#define MAX_GRID 100
#define MAX_HEIGHT 100

int grid[MAX_GRID][MAX_GRID];
int cache[MAX_GRID][MAX_GRID];

int rows, columns;

bool isLower(int si, int sj, int ei, int ej)
{
    if (ei < 0 || ei >= rows || ej < 0 || ej >= columns)
        return false;
    return grid[si][sj] > grid[ei][ej];
}

int solve(int si, int sj)
{
    if (cache[si][sj] != -1)
        return cache[si][sj];

    int mi[] = { -1, 1, 0, 0 };
    int mj[] = { 0, 0, -1, 1 };

    int max = 1;

    for (int i = 0; i < 4; i++)
    {
        int ei = si + mi[i];
        int ej = sj + mj[i];

        if (!isLower(si, sj, ei, ej))
            continue;

        int dist = solve(ei, ej) + 1;
        if (dist > max)
            max = dist;
    }

    cache[si][sj] = max;
    return max;
}

int main()
{
    int tests;
    scanf("%d", &tests);

    for (int t = 0; t < tests; t++)
    {
        int c;
        while ((c = getchar()) != ' ')
            if (c != '\n') printf("%c", c);

        scanf("%d %d", &rows, &columns);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                scanf("%d", &grid[i][j]);
                cache[i][j] = -1;
            }
        }

        int max = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                solve(i, j);
                if (cache[i][j] > max)
                    max = cache[i][j];
            }
        }

        printf(": %d\n", max);
    }
}

/*

2
Feldberg 10 5
56 14 51 58 88
26 94 24 39 41
24 16 8 51 51
76 72 77 43 10
38 50 59 84 81
5 23 37 71 77
96 10 93 53 82
94 15 96 69 9
74 0 62 38 96
37 54 55 82 38
Spiral 5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

Feldberg: 7
Spiral: 25

*/