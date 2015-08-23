#include <stdio.h>
#include <cstdlib>

using namespace std;

int length;
int cutCount;

int cuts[50];

int minCut;

// algorithm is wrong, consider dynamic programming
void doCut(int start, int end)
{
    if (start == end)
        return;

    int idealCut = (end - start) / 2;

    int curBest = -1;
    int curScore = -1;
    for (int i = 0; i < cutCount; i++)
    {
        if (cuts[i] > start && cuts[i] < end)
        {
            int newScore = abs(cuts[i] - idealCut);
            if (curScore == -1 || newScore < curScore)
            {
                curBest = cuts[i];
                curScore = newScore;
            }
        }
    }

    if (curBest != -1)
    {
        printf("%d, %d : cut=%d length=%d\n", start, end, curBest, end - start);
        minCut += end - start;
        doCut(start, curBest);
        doCut(curBest, end);
    }
}

// unfinished
int main()
{
    while (true)
    {
        scanf("%d", &length);
        if (length == 0) break;

        scanf("%d", &cutCount);

        for (int i = 0; i < cutCount; i++)
            scanf("%d", &cuts[i]);

        minCut = 0;

        doCut(0, length);
        printf("The minimum cutting is %d.\n", minCut);
    }
}

/*

100
3
25 50 75
10
4
4 5 7 8
0

The minimum cutting is 200.
The minimum cutting is 22.

*/