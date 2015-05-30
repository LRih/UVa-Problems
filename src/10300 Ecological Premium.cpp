#include <stdio.h>

using namespace std;

int main()
{
    int count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++)
    {
        int cost = 0;

        int farmers;
        scanf("%d", &farmers);

        for (int i = 0; i < farmers; i++)
        {
            int size, animals, envir;
            scanf("%d %d %d", &size, &animals, &envir);
            cost += (size * envir);
        }

        printf("%d\n", cost);
    }
}

/*

3
5
1 1 1
2 2 2
3 3 3
2 3 4
8 9 2
3
9 1 8
6 12 1
8 1 1
3
10 30 40
9 8 5
100 1000 70

38
86
7445

*/
