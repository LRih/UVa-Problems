#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int test = 1;
    while (true)
    {
        int type;
        scanf("%d", &type);
        if (type == 0) break;

        double a, b, c;
        scanf("%lf %lf %lf", &a, &b, &c);

        double acc, u, v;
        switch (type)
        {
            case 1:
                printf("Case %d: %.3f %.3f\n", test, (a + b) * c / 2, (b - a) / c);
                break;
            case 2:
                acc = (b - a) / c;
                printf("Case %d: %.3f %.3f\n", test, b * acc + ((a - b) * acc) / 2, acc);
                break;
            case 3:
                v = sqrt(a * a + 2 * b * c);
                printf("Case %d: %.3f %.3f\n", test, v, (v - a) / b);
                break;
            case 4:
                u = sqrt(a * a - 2 * b * c);
                printf("Case %d: %.3f %.3f\n", test, u, (a - u) / b);
                break;
        }

        test++;
    }
}

/*

1 10 5 2.0
1 5 10.0 2
2 10 11 2
3 5 1 6
4 5.0 -1 6
0

Case 1: 15.000 -2.500
Case 2: 15.000 2.500
Case 3: 5.250 0.500
Case 4: 6.083 1.083
Case 5: 6.083 1.083

*/
