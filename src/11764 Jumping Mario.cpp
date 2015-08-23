#include <cstdio>

using namespace std;

int main()
{
    int tests;
    scanf ("%d", &tests);

    for (int t = 0; t < tests; t++)
    {
        int high = 0, low = 0;

        int walls;
        scanf("%d", &walls);

        int w1, w2;
        scanf("%d", &w1);

        for (int i = 0; i < walls - 1; i++)
        {
            scanf("%d", &w2);
            if (w1 > w2) low++;
            else if (w1 < w2) high++;
            w1 = w2;
        }

        printf("Case %d: %d %d\n", t + 1, high, low);
    }
}

/*

3
8
1 4 2 2 3 5 3 4
1
9
5
1 2 3 4 5

Case 1: 4 2
Case 2: 0 0
Case 3: 4 0

*/
