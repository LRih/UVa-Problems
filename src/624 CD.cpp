#include <cstdio>
#include <cstring>
#include <cmath>
#define MAX_TRACKS 20

using namespace std;

int target, trackCnt;
int tracks[MAX_TRACKS];
bool chosen[MAX_TRACKS];

int best;
bool bestChosen[MAX_TRACKS];

void findSum(int max, int curMax, int index, int sum)
{
    if (curMax == max)
    {
        if (abs(sum - target) < abs(best - target))
        {
            for (int i = 0; i < trackCnt; i++)
                bestChosen[i] = chosen[i];
            best = sum;
        }
    }
    else
    {
        for (int i = index; i < trackCnt; i++)
        {
            chosen[i] = true;
            findSum(max, curMax + 1, i + 1, sum + tracks[i]);
            chosen[i] = false;
        }
    }
}

// wrong answer
int main()
{
    while (scanf("%d", &target) == 1)
    {
        best = 0;
        memset(chosen, 0, sizeof(chosen));
        memset(bestChosen, 0, sizeof(bestChosen));

        scanf("%d", &trackCnt);
        for (int i = 0; i < trackCnt; i++)
            scanf("%d", &tracks[i]);

        for (int i = trackCnt; i >= 1; i--)
            findSum(i, 0, 0, 0);

        for (int i = 0; i < trackCnt; i++)
            if (bestChosen[i]) printf("%d ", tracks[i]);
        printf("sum:%d\n", best);
    }
}

/*

5 3 1 3 4
10 4 9 8 4 2
20 4 10 5 7 4
90 8 10 23 1 2 3 4 5 7
45 8 4 10 44 43 12 9 8 2

1 4 sum:5
8 2 sum:10
10 5 4 sum:19
10 23 1 2 3 4 5 7 sum:55
4 10 12 9 8 2 sum:45

*/
