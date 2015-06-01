#include <cstdio>
#include <cstring> // memset
#include <climits> // INT_MAX
#include <algorithm> // min
#include <vector>
#include <queue>
#define MAX_NODES 100

using namespace std;

int capacity[MAX_NODES][MAX_NODES];

void addCapacity(int i, int j, int cap)
{
    capacity[i][j] += cap;
    capacity[j][i] += cap;
}

// checks for empty path using BFS
bool isEmptyPath(vector<vector<int> >* nodes, int graph[][MAX_NODES], int start, int end, int path[])
{
    bool visited[MAX_NODES];
    memset(visited, 0, sizeof(visited));
    visited[start] = true;

    queue<int> q;
    q.push(start);

    path[start] = -1;

    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        
        for (int i = 0; i < (*nodes)[cur].size(); i++)
        {
            int next = (*nodes)[cur][i];
            if (!visited[next] && graph[cur][next] > 0)
            {
                q.push(next);
                visited[next] = true;
                path[next] = cur;
            }
        }
    }
    return visited[end];
}

// a.k.a. the ford-fulkerson algorithm 
int getMaxFlow(vector<vector<int> >* nodes, int graph[][MAX_NODES], int start, int end)
{
    int maxFlow = 0;
    int path[MAX_NODES];

    while (isEmptyPath(nodes, graph, start, end, path))
    {
        int curFlow = INT_MAX;

        for (int i = end; i != start; i = path[i])
        {
            int j = path[i];
            curFlow = min(curFlow, capacity[i][j]);
        }

        for (int i = end; i != start; i = path[i])
        {
            int j = path[i];
            addCapacity(i, j, -curFlow);
        }

        maxFlow += curFlow;
    }

    return maxFlow;
}

int main()
{
    int count = 1;
    while (true)
    {
        int nodeCount;
        scanf("%d", &nodeCount);
        if (nodeCount == 0) break;

        // clear matrices
        vector<vector<int> > nodes;
        nodes.clear();
        for (int i = 0; i < nodeCount; i++)
            for (int j = 0; j < nodeCount; j++)
                capacity[i][j] = 0;

        int start, end, edgeCount;
        scanf("%d %d %d", &start, &end, &edgeCount);
        start--; end--;

        // populate nodes
        for (int i = 0; i < nodeCount; i++)
        {
            vector<int> node;
            nodes.push_back(node);
        }

        // populate matrices
        for (int c = 0; c < edgeCount; c++)
        {
            int i, j, cap;
            scanf("%d %d %d", &i, &j, &cap);
            i--; j--;

            nodes[i].push_back(j);
            nodes[j].push_back(i);

            addCapacity(i, j, cap);
        }

        printf("Network %d\n", count);
        printf("The bandwidth is %d.\n\n", getMaxFlow(&nodes, capacity, start, end));

        count++;
    }
}

/*

4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
0

Network 1
The bandwidth is 25.

*/
