#include <cstdio>
#define MAX_N 100000

using namespace std;

int n;
int values[MAX_N];

int indexOf(int k, int v)
{
    int curK = 0;
    for (int i = 0; i < n; i++)
    {
        if (values[i] == v)
        {
            curK++;
            if (curK == k) return i + 1;
        }
    }
    return 0;
}

// time limit
int main()
{
    int m;

    while (scanf("%d %d", &n, &m) == 2)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &values[i]);

        for (int i = 0; i < m; i++)
        {
            int k, v;
            scanf("%d %d", &k, &v);
            printf("%d\n", indexOf(k, v));
        }
    }
}

/*

8 4
1 3 2 2 4 3 2 1
1 3
2 4
3 2
4 2

2
0
7
0

*/
