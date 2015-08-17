#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int cnt;
        scanf("%d", &cnt);

        int max = -1;
        for (int j = 0; j < cnt; j++)
        {
            int spd;
            scanf("%d", &spd);

            if (spd > max) max = spd;
        }

        printf("Case %d: %d\n", i + 1, max);
    }
}

/*

2
5 9 3 5 2 6
1 2

Case 1: 9
Case 2: 2

*/
