#include <cstdio>
#include <cstring>
#include <queue>
#define MAX_PEOPLE 2500
#define MAX_FRIENDS 16

using namespace std;

int peopleCnt;
int people[MAX_PEOPLE][MAX_FRIENDS];
int maxBoom, boomDay;

struct agent
{
    int id, day;
};

void findBoom(int start)
{
    bool knows[MAX_PEOPLE];
    memset(knows, 0, sizeof(knows));

    maxBoom = 0;
    boomDay = 1;

    agent s = { start, 1 };
    queue<agent> q;
    q.push(s);
    knows[s.id] = true;

    int curBoom = 0;
    int curDay = 1;

    while (!q.empty())
    {
        agent cur = q.front(); q.pop();

        if (cur.day > curDay)
        {
            if (curBoom > maxBoom)
            {
                maxBoom = curBoom;
                boomDay = curDay;
            }
            curBoom = 0;
            curDay++;
        }

        for (int i = 0; people[cur.id][i] != -1; i++)
        {
            if (knows[people[cur.id][i]]) continue;

            agent next = { people[cur.id][i], cur.day + 1 };
            q.push(next);
            knows[next.id] = true;
            curBoom++;
        }
    }
}

int main()
{
    scanf("%d", &peopleCnt);
    for (int i = 0; i < peopleCnt; i++)
    {
        int friendCnt;
        scanf("%d", &friendCnt);
        for (int j = 0; j < friendCnt; j++)
            scanf("%d", &people[i][j]);
        people[i][friendCnt] = -1;
    }

    int testCnt;
    scanf("%d", &testCnt);
    for (int i = 0; i < testCnt; i++)
    {
        int start;
        scanf("%d", &start);
        
        findBoom(start);
        if (maxBoom == 0) printf("0\n");
        else printf("%d %d\n", maxBoom, boomDay);
    }
}


/*

6
2 1 2
2 3 4
3 0 4 5
1 4
0
2 0 2
3
0
4
5

3 2
0
2 1

*/
