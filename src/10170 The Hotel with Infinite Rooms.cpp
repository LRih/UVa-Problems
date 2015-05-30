#include <stdio.h>
#include <math.h>

using namespace std;

// unfinished
int main()
{
    // int size, day;
    // while (scanf("%d %d", size, day) == 2)
    // {

    // }
    for (int i = 1; i <= 15; i++)
    {
        // for initial group size = 1 only
        // derived from n(n+1)/2
        int ans = (sqrt(8*i + 1) - 1) / 2;
        printf("%d %d\n", i, ans);
    }
}

/*

1 6
3 10
3 14

3
5
6

*/