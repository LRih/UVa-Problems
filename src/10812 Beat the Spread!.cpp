#include <cstdio>

using namespace std;

// wrong answer
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        long sum, dif;
        scanf("%ld %ld", &sum, &dif);

        long a = (sum + dif) / 2;
        long b = (sum - dif) / 2;
        if ((sum + dif) % 2 != 0 || a < 0 || b < 0) printf("impossible\n");
        else printf("%ld %ld\n", a, b);
    }
}

/*

2
40 20
20 40

30 10
impossible

*/
