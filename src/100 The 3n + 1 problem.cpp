#include <stdio.h>
#include <algorithm>

using namespace std;

int getCycle(int n)
{
    int cycle = 1;
    while (n != 1)
    {
        if (n % 2 != 0) n = 3 * n + 1;
        else n /= 2;
        cycle++;
    }
    return cycle;
}

int main()
{
    int i, j, k, l;
    while (scanf("%d %d", &i, &j) == 2)
    {
        if (i < j)
        {
            k = i;
            l = j;
        }
        else
        {
            k = j;
            l = i;
        }

        int m = 0;
        for (int n = k; n <= l; n++)
            m = max(getCycle(n), m);

        printf("%d %d %d\n", i, j, m);
    }
}

/*

1 10
100 200
201 210
900 1000

1 10 20
100 200 125
201 210 89
900 1000 174

*/