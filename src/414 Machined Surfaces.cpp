#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int n;
string rows[15];

int getRowLen(int index)
{
    int count = 0;
    for (int i = 0; i < 25; i++)
        if (rows[index][i] == 'X') count++;
    return count;
}

int getMaxRow()
{
    int m = 0;
    for (int i = 0; i < n; i++)
        m = max(getRowLen(i), m);
    return m;
}

int getGap()
{
    int gap = 0;
    int maxRow = getMaxRow();
    for (int i = 0; i < n; i++)
        gap += maxRow - getRowLen(i);
    return gap;
}

int main()
{
    while (true)
    {
        scanf("%d", &n);
        if (n == 0) break;

        getchar();

        for (int i = 0; i < n; i++)
            getline(cin, rows[i]);

        printf("%d\n", getGap());
    }
}

/*

4
XXXX                XXXXX
XXX               XXXXXXX
XXXXX                XXXX
XX                 XXXXXX
2
XXXXXXXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
1
XXXXXXXXX              XX
0

4
0
0

*/
