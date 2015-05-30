#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    unsigned long a, b;
    while (scanf("%lu %lu", &a, &b) == 2)
        printf("%lu\n", a > b ? a - b : b - a);
}

/*

10 12
10 14
100 200

2
4
100

*/
