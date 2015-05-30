#include <stdio.h>

using namespace std;

int getCycle(unsigned n, unsigned limit)
{
    unsigned cycle = 1;
    while (n != 1)
    {
        if (n % 2 != 0) n = 3 * n + 1;
        else n /= 2;
        if (n > limit) return cycle;
        cycle++;
    }
    return cycle;
}

int main()
{
    int cse = 1;
    while (true)
    {
        int n, limit;
        scanf("%d %d", &n, &limit);
        if (n == -1 && limit == -1) break;

        printf("Case %d: A = %d, limit = %d, number of terms = %d\n", cse, n, limit, getCycle(n, limit));
        cse++;
    }
}

/*

3 100
34 100
75 250
27 2147483647
101 304
101 303
-1 -1
 
Case 1: A = 3, limit = 100, number of terms = 8
Case 2: A = 34, limit = 100, number of terms = 14
Case 3: A = 75, limit = 250, number of terms = 3
Case 4: A = 27, limit = 2147483647, number of terms = 112
Case 5: A = 101, limit = 304, number of terms = 26
Case 6: A = 101, limit = 303, number of terms = 1

*/
