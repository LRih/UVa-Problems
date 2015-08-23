#include <cstdio>
#define MAX_N 18

using namespace std;

int values[MAX_N];

int main()
{
    int test = 1, n;
    while (scanf("%d", &n) == 1)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &values[i]);

        long long max = 0;

        for (int i = 0; i < n; i++)
        {
            long long product = 1;
            for (int j = i; j < n; j++)
            {
                product *= values[j];
                if (product > max) max = product;
            }
        }

        printf("Case #%d: The maximum product is %lld.\n\n", test, max);
        test++;
    }
}

/*

3
2 4 -3
5
2 5 -1 2 -1

Case #1: The maximum product is 8.

Case #2: The maximum product is 20.

*/
