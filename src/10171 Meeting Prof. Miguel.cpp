#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#define MAX_NODES 26

using namespace std;

struct agent
{
    int node, cost;
};

struct street
{
    int target, cost;
    bool isYoung;
};

class compare
{
public:
    bool operator() (agent& a1, agent& a2)
    {
        return a1.cost >= a2.cost;
    }
};

int start, end;
vector<vector<street> > streets;
int calcCost[MAX_NODES];
bool visited[MAX_NODES];

vector<int> lowestStreets;
int lowest;

int getDist(int s, int e, bool isYoung)
{
    for (int i = 0; i < MAX_NODES; i++)
        calcCost[i] = INT_MAX;
    memset(visited, 0, sizeof(visited));

    agent a = { s, 0 };
    priority_queue<agent, vector<agent>, compare> q;
    q.push(a);
    calcCost[s] = 0;

    while (!q.empty())
    {
        agent cur = q.top(); q.pop();

        if (visited[cur.node]) continue;
        visited[cur.node] = true;

        for (int i = 0; i < streets[cur.node].size(); i++)
        {
            street st = streets[cur.node][i];
            if (isYoung != st.isYoung) continue;

            int newCost = cur.cost + st.cost;
            if (!visited[st.target] && newCost < calcCost[st.target])
            {
                agent next = { st.target, newCost };
                q.push(next);
                calcCost[st.target] = newCost;
            }
        }
    }

    return calcCost[e];
}

int findLowest()
{
    lowestStreets.clear();
    lowest = INT_MAX;

    for (int i = 0; i < MAX_NODES; i++)
    {
        int dist1 = getDist(start, i, true);
        int dist2 = getDist(end, i, false);

        if (dist1 != INT_MAX && dist2 != INT_MAX)
        {
            if (dist1 + dist2 < lowest)
            {
                lowestStreets.clear();
                lowestStreets.push_back(i);
                lowest = dist1 + dist2;
            }
            else if (dist1 + dist2 == lowest)
                lowestStreets.push_back(i);
        }
    }
}

int main()
{
    for (int i = 0; i < MAX_NODES; i++)
    {
        vector<street> v;
        streets.push_back(v);
    }

    while (true)
    {
        int edgeCnt;
        scanf("%d", &edgeCnt);
        if (edgeCnt == 0) break;

        for (int i = 0; i < MAX_NODES; i++)
            streets[i].clear();

        for (int i = 0; i < edgeCnt; i++)
        {
            getchar();
            char age, dir, n1, n2;
            int cost;
            scanf("%c %c %c %c %d", &age, &dir, &n1, &n2, &cost);

            street st1 = { n2 - 65, cost, age == 'Y' };
            streets[n1 - 65].push_back(st1);
            if (dir == 'B')
            {
                street st2 = { n1 - 65, cost, age == 'Y' };
                streets[n2 - 65].push_back(st2);
            }
        }

        getchar();
        char s, e;
        scanf("%c %c", &s, &e);
        start = s - 65;
        end = e - 65;
        findLowest();

        if (lowest == INT_MAX)
            printf("You will never meet.\n");
        else
        {
            printf("%d", lowest);
            for (int i = 0; i < lowestStreets.size(); i++)
                printf(" %c", lowestStreets[i] + 65);
            putchar('\n');
        }
    }
}

/*

4
Y U A B 4
Y U C A 1
M U D B 6
M B C D 2
A D
2
Y U A B 10
M U C D 20
A D
0

10 B
You will never meet.

*/
