#include <cstdio>
#include <cstdlib>
#include <climits>
#define MAX_BOOKS 10000

using namespace std;

int books[MAX_BOOKS];

int main()
{
    int bookCnt;
    while (scanf("%d", &bookCnt) == 1)
    {
        for (int i = 0; i < bookCnt; i++)
            scanf("%d", &books[i]);

        int money;
        scanf("%d", &money);

        int c1 = 0, c2 = INT_MAX;
        for (int i = 0; i < bookCnt - 1; i++)
        {
            for (int j = i + 1; j < bookCnt; j++)
            {
                if (books[i] + books[j] == money && abs(books[i] - books[j]) < abs(c1 - c2))
                {
                    c1 = books[i];
                    c2 = books[j];
                }
            }
        }
        if (c1 > c2)
            printf("Peter should buy books whose prices are %d and %d.\n\n", c2, c1);
        else
            printf("Peter should buy books whose prices are %d and %d.\n\n", c1, c2);
    }
}

/*

2
40 40
80

5
10 2 6 8 4
10

Peter should buy books whose prices are 40 and 40.

Peter should buy books whose prices are 4 and 6.

*/
