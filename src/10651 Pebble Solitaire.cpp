#include <stdio.h>
#define LEN 12

using namespace std;

char row[LEN];
int moves = 0;

void getMoves(int curMoves)
{
    if (curMoves > moves) moves = curMoves;

    for (int i = 0; i < LEN; i++)
    {
        // valid move to left
        if (i >= 2 && row[i] =='o' && row[i - 1] == 'o' && row[i - 2] == '-')
        {
            row[i] = '-';
            row[i - 1] = '-';
            row[i - 2] = 'o';
            getMoves(curMoves + 1);
            row[i] = 'o';
            row[i - 1] = 'o';
            row[i - 2] = '-';
        }
        // valid move to right
        if (i < LEN - 2 && row[i] =='o' && row[i + 1] == 'o' && row[i + 2] == '-')
        {
            row[i] = '-';
            row[i + 1] = '-';
            row[i + 2] = 'o';
            getMoves(curMoves + 1);
            row[i] = 'o';
            row[i + 1] = 'o';
            row[i + 2] = '-';
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        getchar();

        for (int j = 0; j < LEN; j++)
            row[j] = getchar();

        moves = 0;
        getMoves(0);

        int pegs = 0;
        for (int j = 0; j < LEN; j++)
            if (row[j] == 'o') pegs++;

        printf("%d\n", pegs - moves);
    }
}

/*

5
---oo-------
-o--o-oo----
-o----ooo---
oooooooooooo
oooooooooo-o

1
2
3
12
1

*/
