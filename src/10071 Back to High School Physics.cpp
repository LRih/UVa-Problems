#include <stdio.h>

using namespace std;

int main()
{
    int v, t;
    while (scanf("%d %d", &v, &t) == 2)
        printf("%d\n", v * t * 2);
}

/*

0 0
5 12

0
120

*/
