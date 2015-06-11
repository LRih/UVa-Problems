#include <cstdio>
#define MAX_GRID 100

using namespace std;

int gridCnt;
int grid[MAX_GRID][MAX_GRID];

bool isOddRow(int row)
{
    int count = 0;
    for (int i = 0; i < gridCnt; i++)
        count += grid[row][i];
    return count % 2 != 0;
}

bool isOddCol(int col)
{
    int count = 0;
    for (int i = 0; i < gridCnt; i++)
        count += grid[i][col];
    return count % 2 != 0;
}

int getRowStatus()
{
    int oddRow = -1;
    int oddCnt = 0;
    for (int i = 0; i < gridCnt; i++)
    {
        if (isOddRow(i))
        {
            oddRow = i;
            oddCnt++;
            if (oddCnt == 2) return -2;
        }
    }
    return oddRow;
}

int getColStatus()
{
    int oddCol = -1;
    int oddCnt = 0;
    for (int i = 0; i < gridCnt; i++)
    {
        if (isOddCol(i))
        {
            oddCol = i;
            oddCnt++;
            if (oddCnt == 2) return -2;
        }
    }
    return oddCol;
}

int main()
{
    while (true)
    {
        scanf("%d", &gridCnt);
        if (gridCnt == 0) break;

        for (int i = 0; i < gridCnt; i++)
            for (int j = 0; j < gridCnt; j++)
                scanf("%d", &grid[i][j]);

        int row = getRowStatus();
        int col = getColStatus();

        if (row >= 0 && col >= 0) printf("Change bit (%d,%d)\n", row + 1, col + 1);
        else if (row == -1 && col == -1) printf("OK\n");
        else printf("Corrupt\n");
    }
}

/*

4
1 0 1 0
0 0 0 0
1 1 1 1
0 1 0 1
4
1 0 1 0
0 0 1 0
1 1 1 1
0 1 0 1
4
1 0 1 0
0 1 1 0
1 1 1 1
0 1 0 1
0

OK
Change bit (2,3)
Corrupt

*/
