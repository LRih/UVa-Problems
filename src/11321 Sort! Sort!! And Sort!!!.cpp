#include <cstdio>
#include <cstdlib>
#define MAX_N 10000

using namespace std;

int m, n;
long arr[MAX_N];

int cmp(const void *a, const void *b)
{
    long aa = *(long*)a;
    long bb = *(long*)b;

    long v1 = aa % m;
    long v2 = bb % m;

    if (v1 < v2) return -1;
    else if (v1 > v2) return 1;

    v1 = aa % 2;
    v2 = bb % 2;

    if (v1 > v2) return -1;
    else if (v1 < v2) return 1;

    if (v1 == 1)
    {
        if (aa < bb) return 1;
        else if (aa > bb) return -1;
    }
    else
    {
        if (aa > bb) return 1;
        else if (aa < bb) return -1;
    }

    return 0;
}

// wrong answer
int main()
{
    while (true)
    {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        for (int i = 0; i < n; i++)
            scanf("%ld", &arr[i]);

        printf("%d %d\n", n, m);

        qsort(arr, n, sizeof(long), cmp);

        for (int i = 0; i < n; i++)
            printf("%d\n", arr[i]);
    }
    printf("0 0\n");
}

/*

15 3
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
0 0

15 3
15
9
3
6
12
13
7
1
4
10
11
5
2
8
14
0 0

*/
