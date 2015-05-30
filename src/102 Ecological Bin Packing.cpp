#include <stdio.h>

using namespace std;

int values[9];
int min = -1;
char text[4];

void countMovements(int brown, int green, int clear)
{
    int count = 0;

    switch (brown)
    {
        case 0: count += values[3]; count += values[6]; break;
        case 1: count += values[0]; count += values[6]; break;
        case 2: count += values[0]; count += values[3]; break;
    }
    switch (green)
    {
        case 0: count += values[4]; count += values[7]; break;
        case 1: count += values[1]; count += values[7]; break;
        case 2: count += values[1]; count += values[4]; break;
    }
    switch (clear)
    {
        case 0: count += values[5]; count += values[8]; break;
        case 1: count += values[2]; count += values[8]; break;
        case 2: count += values[2]; count += values[5]; break;
    }
    
    if (min == -1 || count < min)
    {
        min = count;
        text[brown] = 'B';
        text[green] = 'G';
        text[clear] = 'C';
    }
}

int main()
{
    while (scanf("%d %d %d %d %d %d %d %d %d", &values[0], &values[1], &values[2], &values[3], &values[4], &values[5], &values[6], &values[7], &values[8]) == 9)
    {
        min = -1;
        countMovements(0, 2, 1); // BCG
        countMovements(0, 1, 2); // BGC
        countMovements(1, 2, 0); // CBG
        countMovements(2, 1, 0); // CGB
        countMovements(1, 0, 2); // GBC
        countMovements(2, 0, 1); // GCB

        printf("%s %d\n", text, min);
    }
}

/*

1 2 3 4 5 6 7 8 9
5 10 5 20 10 5 10 20 10

BCG 30
CBG 50

*/
