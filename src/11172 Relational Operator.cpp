#include <cstdio>

using namespace std;

int main()
{
    int testCnt;
    scanf("%d", &testCnt);
    while (testCnt--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b) printf(">\n");
        else if (a < b) printf("<\n");
        else printf("=\n");
    }
}

/*

3
10 20
20 10
10 10

<
>
=

*/
