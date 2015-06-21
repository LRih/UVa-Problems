#include <cstdio>
#include <cstring>
#define MAX_REGIONS 100

using namespace std;

int regionCnt;
bool isOff[MAX_REGIONS];

int shift(int cur, int cnt)
{
    while (cnt > 0)
    {
        cur++;
        if (cur > regionCnt) cur = 1;
        if (!isOff[cur]) cnt--;
    }
    return cur;
}

bool isValid(int m)
{
    int cur = 1;
    int offCnt = 0;
    while (true)
    {
        isOff[cur] = true;
        offCnt++;

        if (cur == 13)
            return offCnt == regionCnt;

        cur = shift(cur, m);
    }
}

int main()
{
    while (true)
    {
        scanf("%d", &regionCnt);
        if (regionCnt == 0) break;

        int m = 0;
        do
        {
            memset(isOff, 0, sizeof(isOff));
            m++;
        }
        while (!isValid(m));

        printf("%d\n", m);
    }
}

/*

17
0

7

*/
