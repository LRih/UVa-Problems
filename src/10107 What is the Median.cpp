#include <cstdio>
#include <cstdlib>

using namespace std;

unsigned values[10000];

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int cnt = 0;
    unsigned n;
    while (scanf("%u", &n) == 1)
    {
        values[cnt] = n;
        cnt++;
        qsort(values, cnt, sizeof(int), cmp);

        if (cnt % 2 == 0)
            printf("%u\n", (values[cnt / 2 - 1] + values[cnt / 2]) / 2);
        else
            printf("%u\n", values[cnt / 2]);
    }
}

/*

1
3
4
60
70
50
2

1
2
3
3
4
27
4

*/
