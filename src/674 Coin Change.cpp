#include <cstdio>
#include <algorithm>

using namespace std;

int total;

int countWays()
{
    int ways = 1;
    int denom[] = { 50, 25, 10, 5, 1 };
    int reps[] = { 37, 13, 4, 2, 1 };
    int counts[] = { 0, 0, 0, 0, 0 };

    for (int i = 0; i < 5; i++)
    {
        counts[i] = total / denom[i];
        total = max(total - denom[i] * counts[i], 0);
    }

    for (int i = 0; i < 5; i++)
        if (counts[i] > 0)
            ways *= reps[i] * counts[i];

    return ways;
}

// wrong answer
int main()
{
    while (scanf("%d", &total) == 1)
    {
        printf("%d\n", countWays());
    }
}

/*

11
26

4
13

*/
