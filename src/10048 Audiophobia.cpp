#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_NODES 100

using namespace std;

struct edge
{
    int dst, sound;
};

struct agent
{
    int node, sound;
};

class compare
{
public:
    bool operator() (agent& a1, agent& a2)
    {
        return a1.sound >= a2.sound;
    }
};

int nodeCnt;
vector<vector<edge> > network;
bool visited[MAX_NODES];
int cost[MAX_NODES];

int getPath(int s, int e)
{
    for (int i = 0; i < nodeCnt; i++)
    {
        visited[i] = false;
        cost[i] = INT_MAX;
    }

    agent a = { s, 0 };
    priority_queue<agent, vector<agent>, compare> q;
    q.push(a);

    cost[s] = 0;

    while (!q.empty())
    {
        agent cur = q.top(); q.pop();

        if (visited[cur.node]) continue;
        visited[cur.node] = true;

        for (int i = 0; i < network[cur.node].size(); i++)
        {
            edge e = network[cur.node][i];

            int maxSound = max(cur.sound, e.sound);
            if (maxSound < cost[e.dst])
            {
                agent next = { e.dst, maxSound };
                q.push(next);
                cost[e.dst] = maxSound;
            }
        }
    }

    return cost[e];
}

int main()
{
    int test = 0;
    while (true)
    {
        int edgeCnt, trials;
        scanf("%d %d %d", &nodeCnt, &edgeCnt, &trials);
        if (nodeCnt == 0 && edgeCnt == 0 && trials == 0) break;

        network.clear();
        for (int i = 0; i < nodeCnt; i++)
        {
            vector<edge> v;
            network.push_back(v);
        }

        for (int i = 0; i < edgeCnt; i++)
        {
            int n1, n2, sound;
            scanf("%d %d %d", &n1, &n2, &sound);
            n1--; n2--;
            edge e1 = { n2, sound };
            edge e2 = { n1, sound };
            network[n1].push_back(e1);
            network[n2].push_back(e2);
        }

        if (test > 0) putchar('\n');
        printf("Case #%d\n", test + 1);
        for (int i = 0; i < trials; i++)
        {
            int s, e;
            scanf("%d %d", &s, &e);
            s--; e--;
            int path = getPath(s, e);
            if (path == INT_MAX) printf("no path\n");
            else printf("%d\n", path);
        }

        test++;
    }
}

/*

7 9 3
1 2 50
1 3 60
2 4 120
2 5 90
3 6 50
4 6 80
4 7 70
5 7 40
6 7 140
1 7
2 6
6 2
7 6 3
1 2 50
1 3 60
2 4 120
3 6 50
4 6 80
5 7 40
7 5
1 7
2 4
0 0 0

Case #1
80
60
60

Case #2
40
no path
80

*/
