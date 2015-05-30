#include <stdio.h>
#include <math.h>

using namespace std;

// unfinished
int main()
{
    while (true)
    {
        int n;
        scanf("%d", &n);
        if (n == 0) break;

        int diag = sqrt(n);
        printf("%d\n", diag);
    }
}

/*

8
20
25
0

2 3
5 4
1 5

*/
