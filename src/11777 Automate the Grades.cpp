#include <cstdio>

using namespace std;

int main()
{
    int tests;
    scanf ("%d", &tests);

    for (int t = 0; t < tests; t++)
    {
        double sum;
        int t1, t2, final, att, c1, c2, c3;
        scanf("%d %d %d %d %d %d %d", &t1, &t2, &final, &att, &c1, &c2, &c3);

        sum = t1 + t2 + final + att;
        if (c1 >= c3 && c2 >= c3) sum += (c1 + c2) / (double)2;
        else if (c1 >= c2 && c3 >= c2) sum += (c1 + c3) / (double)2;
        else if (c2 >= c1 && c3 >= c1) sum += (c2 + c3) / (double)2;

        if (sum >= 90) printf("Case %d: A\n", t + 1);
        else if (sum >= 80) printf("Case %d: B\n", t + 1);
        else if (sum >= 70) printf("Case %d: C\n", t + 1);
        else if (sum >= 60) printf("Case %d: D\n", t + 1);
        else printf("Case %d: F\n", t + 1);
    }
}

/*

3
15 18 25 8 15 17 12
20 20 30 10 20 20 20
20 20 30 10 18 0 0

Case 1: B
Case 2: A
Case 3: B

*/
