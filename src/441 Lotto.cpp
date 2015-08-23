#include <cstdio>
#define MAX_N 15
#define LOTTO_CNT 6

using namespace std;

int n;
int values[MAX_N];
int buffer[MAX_N];

void printBuffer()
{
    for (int i = 0; i < LOTTO_CNT; i++)
    {
        if (i > 0) putchar(' ');
        printf("%d", buffer[i]);
    }
    printf("\n");
}

void combin(int start, int length)
{
    if (length == LOTTO_CNT)
    {
        printBuffer();
        return;
    }

    for (int i = start; i < n; i++)
    {
        buffer[length] = values[i];
        combin(i + 1, length + 1);
    }
}

int main()
{
    int testCnt = 0;

    while (true)
    {
        scanf("%d", &n);
        if (n == 0) break;

        for (int i = 0; i < n; i++)
            scanf("%d", &values[i]);

        if (testCnt > 0) printf("\n");

        combin(0, 0);

        testCnt++;
    }
}

/*

7 1 2 3 4 5 6 7
8 1 2 3 5 8 13 21 34
0

1 2 3 4 5 6
1 2 3 4 5 7
1 2 3 4 6 7
1 2 3 5 6 7
1 2 4 5 6 7
1 3 4 5 6 7
2 3 4 5 6 7

1 2 3 5 8 13
1 2 3 5 8 21
1 2 3 5 8 34
1 2 3 5 13 21
1 2 3 5 13 34
1 2 3 5 21 34
1 2 3 8 13 21
1 2 3 8 13 34
1 2 3 8 21 34
1 2 3 13 21 34
1 2 5 8 13 21
1 2 5 8 13 34
1 2 5 8 21 34
1 2 5 13 21 34
1 2 8 13 21 34
1 3 5 8 13 21
1 3 5 8 13 34
1 3 5 8 21 34
1 3 5 13 21 34
1 3 8 13 21 34
1 5 8 13 21 34
2 3 5 8 13 21
2 3 5 8 13 34
2 3 5 8 21 34
2 3 5 13 21 34
2 3 8 13 21 34
2 5 8 13 21 34
3 5 8 13 21 34

*/
