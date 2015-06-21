#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAX_BEADS 1000
#define MAX_COLORS 51

using namespace std;

struct edge
{
    int col1, col2;
    bool used;
};

int beadCnt;
vector<edge> beads;
int beadCnts[MAX_COLORS];
bool visited[MAX_COLORS];

bool isConnected()
{
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(beads[0].col1);
    visited[beads[0].col1] = true;

    while (!q.empty())
    {
        int cur = q.front(); q.pop();

        for (int i = 0; i < beadCnt; i++)
        {
            if (beads[i].col1 == cur && beads[i].col2 != cur && !visited[beads[i].col2])
            {
                q.push(beads[i].col2);
                visited[beads[i].col2] = true;
            }
            if (beads[i].col2 == cur && beads[i].col1 != cur && !visited[beads[i].col1])
            {
                q.push(beads[i].col1);
                visited[beads[i].col1] = true;
            }
        }
    }

    for (int i = 0; i < beadCnt; i++)
        if (!visited[beads[i].col1] || !visited[beads[i].col2]) return false;
    return true;
}

bool isEvenEdges()
{
    memset(beadCnts, 0, sizeof(beadCnts));
    for (int i = 0; i < beads.size(); i++)
    {
        beadCnts[beads[i].col1]++;
        beadCnts[beads[i].col2]++;
    }

    for (int i = 1; i < MAX_COLORS; i++)
        if (beadCnts[i] % 2 != 0) return false;
    return true;
}

int getCount(int col)
{
    int count = 0;
    for (int i = 0; i < beads.size(); i++)
    {
        if (beads[i].col1 == col) count++;
        if (beads[i].col2 == col) count++;
    }
    return count;
}

void printCycle()
{
    int startEdgeCnt = getCount(beads[0].col1);
    int lastCol = beads[0].col2;
    int used = 1;

    printf("%d %d\n", beads[0].col1, beads[0].col2);
    beads[0].used = true;
    startEdgeCnt--;
    if (beads[0].col1 == beads[0].col2) startEdgeCnt--;

    while (used != beadCnt)
    {
        for (int i = 0; i < beadCnt; i++)
        {
            if (beads[i].used) continue;

            if (beads[i].col1 == lastCol)
            {
                if (beads[i].col1 != beads[i].col2)
                {
                    if (beads[i].col2 == beads[0].col1 && startEdgeCnt == 1 && used != beadCnt - 1)
                        continue;
                }
                printf("%d %d\n", beads[i].col1, beads[i].col2);
                lastCol = beads[i].col2;
                beads[i].used = true;
                used++;
                if (beads[i].col1 == beads[0].col1) startEdgeCnt--;
                if (beads[i].col2 == beads[0].col1) startEdgeCnt--;
            }
            else if (beads[i].col2 == lastCol)
            {
                if (beads[i].col1 != beads[i].col2)
                {
                    if (beads[i].col1 == beads[0].col1 && startEdgeCnt == 1 && used != beadCnt - 1)
                        continue;
                }
                printf("%d %d\n", beads[i].col2, beads[i].col1);
                lastCol = beads[i].col1;
                beads[i].used = true;
                used++;
                if (beads[i].col1 == beads[0].col1) startEdgeCnt--;
                if (beads[i].col2 == beads[0].col1) startEdgeCnt--;
            }
        }
    }
}

// time limit
int main()
{
    int tests;
    scanf("%d", &tests);

    for (int t = 0; t < tests; t++)
    {
        beads.clear();

        scanf("%d", &beadCnt);
        for (int i = 0; i < beadCnt; i++)
        {
            int col1, col2;
            scanf("%d %d", &col1, &col2);
            edge e = { col1, col2, false };
            beads.push_back(e);
        }

        if (t > 0) putchar('\n');

        if (isEvenEdges() && isConnected())
        {
            printf("Case #%d\n", t + 1);
            printCycle();
        }
        else
            printf("Case #%d\nsome beads may be lost\n", t + 1);
    }
}

/*

2
5
1 2
2 3
3 4
4 5
5 6
5
2 1
2 2
3 4
3 1
2 4

1
3
2 1
2 1
1 1

Case #1
some beads may be lost

Case #2
2 1
1 3
3 4
4 2
2 2

*/
