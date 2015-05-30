#include <stdio.h>

using namespace std;

int n;
int belt[25][25];

void printBelt()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d:", i);
        for (int j = 0; j < n; j++)
        {
            if (belt[i][j] != -1)
            {
                if (j > 0) printf(" ");
                printf("%d", belt[i][j]);
            }
        }
        printf("\n");
    }
}

// unfinished
int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        belt[i][0] = i;
        for (int j = 1; j < n; j++)
            belt[i][j] = -1;
    }

    char cmd1[5], cmd2[5];
    int block1, block2;

    while (scanf("%s %d %s %d", cmd1, &block1, cmd2, &block2) == 4)
    {
        printBelt();
    }

    printBelt();
}

/*

10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 over 5
move 2 over 1
move 4 over 9
quit

 0: 0
 1: 1 9 2 4
 2:
 3: 3
 4:
 5: 5 8 7 6
 6:
 7:
 8:
 9:

 */
