#include <cstdio>

using namespace std;

int main()
{
    int m, n;
    while (scanf("%d %d", &m, &n) == 2)
        printf("%d\n", m * n - 1);
}

/*

2 2
1 1
1 5

3
0
4

*/
