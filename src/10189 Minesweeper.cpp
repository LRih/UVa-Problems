#include <stdio.h>

using namespace std;

int h, w;
char grid[100][100];

int isValid(int i, int j)
{
    return i >= 0 && i < h && j >= 0 && j < w;
}

int getMines(int i, int j)
{
    int mines = 0;
    if (isValid(i - 1, j - 1) && grid[i - 1][j - 1] == '*') mines++;
    if (isValid(i - 1, j) && grid[i - 1][j] == '*') mines++;
    if (isValid(i - 1, j + 1) && grid[i - 1][j + 1] == '*') mines++;
    if (isValid(i, j - 1) && grid[i][j - 1] == '*') mines++;
    if (isValid(i, j + 1) && grid[i][j + 1] == '*') mines++;
    if (isValid(i + 1, j - 1) && grid[i + 1][j - 1] == '*') mines++;
    if (isValid(i + 1, j) && grid[i + 1][j] == '*') mines++;
    if (isValid(i + 1, j + 1) && grid[i + 1][j + 1] == '*') mines++;
    return mines;
}

// wrong answer
int main()
{
    int field = 0;
    while (true)
    {
        field++;
        scanf("%d %d", &h, &w);
        if (h == 0 && w == 0) break;

        for (int i = 0; i < h; i++)
        {
            getchar();
            for (int j = 0; j < w; j++)
                grid[i][j] = getchar();
        }

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (grid[i][j] == '.') grid[i][j] = getMines(i, j) + 48;


        if (field > 0) printf("\n");
        printf("Field #%d:\n", field);
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
                printf("%c", grid[i][j]);
            printf("\n");
        }
    }
}

/*

4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0

Field #1:
*100
2210
1*10
1110

Field #2:
**100
33200
1*100

*/
