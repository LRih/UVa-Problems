#include <cstdio>
#include <climits>
#include <vector>
#define MAX_ROOMS 100

using namespace std;

struct edge
{
    int src, dst;
}

int roomCnt;
vector<edge> rooms;
int energy[MAX_ROOMS];
int cost[MAX_ROOMS];

bool canWin()
{
    for (int i = 0; i < roomCnt - 1; i++)
    {
        for (int j = 0; j < rooms.size(); j++)
        {
            edge e = rooms[j];
            if (cost[e.src] + energy[e.dst] < cost[e.dst])
                cost[e.dst] = cost[e.src] + energy[e.dst];
        }
    }

    for (int j = 0; j < rooms.size(); j++)
    {
        edge e = rooms[j];
        if (cost[e.src] + energy[e.dst] < cost[e.dst])
            cost[e.dst] = cost[e.src] + energy[e.dst];
    }
}

// unfinished
int main()
{
    while (true)
    {
        int roomCnt;
        scanf("%d", &roomCnt);
        if (roomCnt == -1) break;

        rooms.clear();
        cost[0] = 0;
        for (int i = 1; i < roomCnt; i++)
            cost[i] = INT_MAX;

        for (int i = 0; i < roomCnt; i++)
        {
            int energy, edgeCnt;
            scanf("%d %d", &energy, &edgeCnt);
            energy[i] = energy;

            for (int j = 0; j < edgeCnt; j++)
            {
                int dst;
                scanf("%d", &dst);
                edge e = { i, dst - 1 };
                rooms.push_back(e);
            }
        }

        if (canWin()) printf("winnable\n");
        else printf("hopeless\n");
    }
}

/*

5
0 1 2
-60 1 3
-60 1 4
20 1 5
0 0
5
0 1 2
20 1 3
-60 1 4
-60 1 5
0 0
5
0 1 2
21 1 3
-60 1 4
-60 1 5
0 0
5
0 1 2
20 2 1 3
-60 1 4
-60 1 5
0 0
-1

hopeless
hopeless
winnable
winnable

*/
