#include <cstdio>
#include <cstring>
#include <queue>
#define MAX_BTNS 10

using namespace std;

int values[10000];
int lock, unlock;
int btnCnt;
int buttons[MAX_BTNS];

int getClicks()
{
    queue<int> q;
    q.push(lock);
    values[lock] = 0;

    while (!q.empty())
    {
        int cur = q.front(); q.pop();

        for (int i = 0; i < MAX_BTNS; i++)
        {
            int next = (cur + buttons[i]) % 10000;
            if (values[next] == -1)
            {
                values[next] = cur;
                q.push(next);
            }
        }
    }

    if (lock == unlock)
        return 0;
    else if (values[unlock] != -1)
    {
        int clicks = 1;
        int cur = values[unlock];
        while (cur != lock)
        {
            cur = values[cur];
            clicks++;
        }
        return clicks;
    }
    else
        return -1;
}

int main()
{
    int cnt = 1;
    while (true)
    {
        scanf("%d %d %d", &lock, &unlock, &btnCnt);
        if (lock == 0 && unlock == 0 && btnCnt == 0) break;

        for (int i = 0; i < 10000; i++)
            values[i] = -1;

        for (int i = 0; i < btnCnt; i++)
            scanf("%d", &buttons[i]);

        int clicks = getClicks();
        if (clicks != -1) printf("Case %d: %d\n", cnt, clicks);
        else printf("Case %d: Permanently Locked\n", cnt);

        cnt++;
    }
}

/*

0000 9999 1
1000
0000 9999 1
0001
5234 1212 3
1023 0101 0001
0 0 0

Case 1: Permanently Locked
Case 2: 9999
Case 3: 48

*/
