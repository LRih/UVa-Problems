#include <cstdio>
#include <climits>

using namespace std;

int main()
{
    int peopleCnt, budget, hotelCnt, weekCnt;
    while (scanf("%d %d %d %d", &peopleCnt, &budget, &hotelCnt, &weekCnt) == 4)
    {
        int min = INT_MAX;

        for (int i = 0; i < hotelCnt; i++)
        {
            bool overBudget;
            int cost;
            scanf("%d", &cost);

            overBudget = (cost * peopleCnt > budget);

            for (int j = 0; j < weekCnt; j++)
            {
                int bedCnt;
                scanf("%d", &bedCnt);

                if (!overBudget && bedCnt >= peopleCnt && min > cost * peopleCnt)
                    min = cost * peopleCnt;
            }
        }

        if (min == INT_MAX) printf("stay home\n");
        else printf("%d\n", min);
    }
}

/*

3 1000 2 3
200
0 2 2
300
27 3 20
5 2000 2 4
300
4 3 0 4
450
7 8 0 13

900
stay home

*/
