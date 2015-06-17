#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#define MAX_NODES 50000

using namespace std;

int nodeCnt;
int network[MAX_NODES];
int cache[MAX_NODES];
bool visited[MAX_NODES];

int trace(int start)
{
    if (visited[start]) return cache[start];

    vector<int> path;
    path.push_back(start);
    visited[start] = true;

    while (true)
    {
        int cur = path[path.size() - 1];
        int next = network[cur];

        // arrived at pre-calculated path
        if (visited[next] && cache[next] != -1)
        {
            for (int i = 0; i < path.size(); i++)
                cache[path[i]] = cache[next] + path.size() - i;
            return cache[start];
        }

        // arrived at cycle
        if (visited[next])
        {
            int i;
            int cycleLen = 1;
            for (i = path.size() - 1; path[i] != next; i--)
                cycleLen++;

            for (int j = i; j < path.size(); j++)
                cache[path[j]] = cycleLen;

            for (int j = i - 1; j >= 0; j--)
            {
                cycleLen++;
                cache[path[j]] = cycleLen;
            }
            return cache[start];
        }

        path.push_back(next);
        visited[next] = true;
    }
}

int getLongest()
{
    for (int i = 0; i < nodeCnt; i++)
    {
        visited[i] = false;
        cache[i] = -1;
    }

    int bestStart = -1;
    int max = 0;
    for (int i = 0; i < nodeCnt; i++)
    {
        int newMax = trace(i);
        if (newMax > max)
        {
            bestStart = i;
            max = newMax;
        }
    }

    return bestStart;
}

int main()
{
    int tests;
    scanf("%d", &tests);
    for (int t = 0; t < tests; t++)
    {
        scanf("%d", &nodeCnt);
        for (int i = 0; i < nodeCnt; i++)
        {
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            network[n1 - 1] = n2 - 1;
        }

        printf("Case %d: %d\n", t + 1, getLongest() + 1);
    }
}

/*

3
3
1 2
2 3
3 1
4
1 2
2 1
4 3
3 2
5
1 2
2 1
5 3
3 4
4 5

Case 1: 1
Case 2: 4
Case 3: 3

*/
