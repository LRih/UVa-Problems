#include <cstdio>
#include <climits>
#include <cmath>
#define MAX_N 1000

using namespace std;

int values[MAX_N];

int main()
{
    int test = 1;
    while (true)
    {
        int n;
        scanf("%d", &n);
        if (n == 0) break;

        for (int i = 0; i < n; i++)
            scanf("%d", &values[i]);

        printf("Case %d:\n", test);

        int m;
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            int target;
            scanf("%d", &target);

            int best = INT_MAX;
            for (int j = 0; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    int sum = values[j] + values[k];
                    if (abs(sum - target) < abs(best - target))
                        best = sum;
                }
            }
            printf("Closest sum to %d is %d.\n", target, best);
        }

        test++;
    }
}

/*

5
3
12
17
33
34
3
1
51
30
3
1
2
3
3
1
2
3
3
1
2
3
3
4
5
6
0

Case 1:
Closest sum to 1 is 15.
Closest sum to 51 is 51.
Closest sum to 30 is 29.
Case 2:
Closest sum to 1 is 3.
Closest sum to 2 is 3.
Closest sum to 3 is 3.
Case 3:
Closest sum to 4 is 4.
Closest sum to 5 is 5.
Closest sum to 6 is 5.

*/
