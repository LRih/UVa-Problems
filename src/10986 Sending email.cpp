#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#define MAX_SERVERS 20000

using namespace std;

struct agent
{
    int node, cost;

    agent(int _node, int _cost)
    {
        node = _node;
        cost = _cost;
    }
};

class compare
{
public:
    bool operator() (agent& a1, agent& a2)
    {
        return a1.cost >= a2.cost;
    }
};

struct link
{
    int node, lat;
};

vector<vector<link> > nodes;
int cost[MAX_SERVERS];
int visited[MAX_SERVERS];
int start, end;

void findCost()
{
    priority_queue<agent, vector<agent>, compare> q;
    q.push(agent(start, 0));

    while (!q.empty())
    {
        agent cur = q.top(); q.pop();

        if (cur.node == end) break;

        if (visited[cur.node]) continue;
        visited[cur.node] = true;

        for (int i = 0; i < nodes[cur.node].size(); i++)
        {
            link lnk = nodes[cur.node][i];
            if (visited[lnk.node]) continue;

            int newCost = cur.cost + lnk.lat;
            if (newCost < cost[lnk.node])
            {
                q.push(agent(lnk.node, newCost));
                cost[lnk.node] = newCost;
            }
        }
    }

}

int main()
{
    int testCnt;
    scanf("%d", &testCnt);

    for (int c = 0; c < testCnt; c++)
    {
        nodes.clear();

        int nodeCnt, cableCnt;
        scanf("%d %d %d %d", &nodeCnt, &cableCnt, &start, &end);

        for (int i = 0; i < nodeCnt; i++)
        {
            cost[i] = INT_MAX;
            visited[i] = false;

            vector<link> node;
            nodes.push_back(node);
        }

        for (int i = 0; i < cableCnt; i++)
        {
            int n1, n2, lat;
            scanf("%d %d %d", &n1, &n2, &lat);
            link l1 = { n2, lat };
            link l2 = { n1, lat };
            nodes[n1].push_back(l1);
            nodes[n2].push_back(l2);
        }

        findCost();
        if (cost[end] != INT_MAX) printf("Case #%d: %d\n", c + 1, cost[end]);
        else printf("Case #%d: unreachable\n", c + 1);
    }
}

/*

3
2 1 0 1
0 1 100
3 3 2 0
0 1 100
0 2 200
1 2 50
2 0 0 1

Case #1: 100
Case #2: 150
Case #3: unreachable

*/
