#include <cstdio>
#include <climits>
#include <vector>
#define MAX_NODES 1000

using namespace std;

struct edge
{
    int start, end, cost;
};

int nodeCnt;
vector<edge> network;
int cost[MAX_NODES];

// bellman ford
bool findNegativeCycle()
{
    cost[0] = 0;
    for (int i = 1; i < nodeCnt; i++)
        cost[i] = INT_MAX;

    for (int i = 0; i < nodeCnt - 1; i++)
    {
        for (int j = 0; j < network.size(); j++)
        {
            edge e = network[j];
            if (cost[e.start] + e.cost < cost[e.end])
                cost[e.end] = cost[e.start] + e.cost;
        }
    }

    for (int j = 0; j < network.size(); j++)
    {
        edge e = network[j];
        if (cost[e.start] + e.cost < cost[e.end])
            return true;
    }

    return false;
}

int main()
{
    int tests;
    scanf("%d", &tests);

    for (int t = 0; t < tests; t++)
    {
        network.clear();

        int edgeCnt;
        scanf("%d %d", &nodeCnt, &edgeCnt);

        for (int i = 0; i < edgeCnt; i++)
        {
            edge e;
            scanf("%d %d %d", &e.start, &e.end, &e.cost);
            network.push_back(e);
        }

        if (findNegativeCycle()) printf("possible\n");
        else printf("not possible\n");
    }
}

/*

2
3 3
0 1 1000
1 2 15
2 1 -42
4 4
0 1 10
1 2 20
2 3 30
3 0 -60

possible
not possible

*/
