#include <cstdio>
#include <cmath>

using namespace std;

// wrong answer, avg does not work
int main()
{
    int houses[500];

    int tests;
    scanf("%d", &tests);
    while (tests--)
    {
        int n;
        scanf("%d", &n);

        int avg = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &houses[i]);
            avg += houses[i];
        }
        avg /= n;

        int dist = 0;
        for (int i = 0; i < n; i++)
            dist += abs(houses[i] - avg);

        printf("%d\n", dist);
    }
}

/*

2
2 2 4
3 2 4 6

2
4

*/
