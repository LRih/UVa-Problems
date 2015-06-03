#include <cstdio>

using namespace std;

int main()
{
    int tests;
    scanf("%d", &tests);
    for (int t = 0; t < tests; t++)
    {
        int a, b;
        scanf("%d\n%d", &a, &b);

        int sum = 0;
        for (int i = a; i <= b; i++)
            if (i % 2 != 0) sum += i;

        printf("Case %d: %d\n", t + 1, sum);
    }
}

/*

2
1
5
3
5

Case 1: 9
Case 2: 8

*/
