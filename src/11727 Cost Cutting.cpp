#include <cstdio>

using namespace std;

int main()
{
    int tests = 0;
    scanf("%d", &tests);
    for (int i = 0; i < tests; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a < b && b < c || c < b && b < a) printf("Case %d: %d\n", i + 1, b);
        else if (b < a && a < c || c < a && a < b) printf("Case %d: %d\n", i + 1, a);
        else printf("Case %d: %d\n", i + 1, c);
    }
}

/*

3
1000 2000 3000
3000 2500 1500
1500 1200 1800

Case 1: 2000
Case 2: 2500
Case 3: 1500

*/
