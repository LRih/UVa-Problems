#include <cstdio>
#include <cstring>
#include <queue>
#define MAX_BTNS 10

using namespace std;

bool visited[10000];
int btnCnt;
int buttons[MAX_BTNS];

struct agent
{
    int value, clicks;
};

int getClicks(int start, int end)
{
    agent s = { start, 0 };

    queue<agent> q;
    q.push(s);
    visited[s.value] = true;

    while (!q.empty())
    {
        agent cur = q.front(); q.pop();
        if (cur.value == end) return cur.clicks;

        for (int i = 0; i < MAX_BTNS; i++)
        {
            agent next = { (cur.value + buttons[i]) % 10000, cur.clicks + 1 };

            if (!visited[next.value])
            {
                visited[next.value] = true;
                q.push(next);
            }
        }
    }

    return -1;
}

// wrong answer
int main()
{
    int cnt = 1;
    while (true)
    {
        int lock, unlock;
        scanf("%d %d %d", &lock, &unlock, &btnCnt);
        if (lock == 0 && unlock == 0 && btnCnt == 0) break;

        for (int i = 0; i < 10000; i++)
            visited[i] = false;

        for (int i = 0; i < btnCnt; i++)
            scanf("%d", &buttons[i]);

        int clicks = getClicks(lock, unlock);
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
