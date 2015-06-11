#include <cstdio>
#include <cstring>
#include <stack>
#define MAX_NODES 50000

using namespace std;

int nodeCnt;
int network[MAX_NODES];
int cache[MAX_NODES];
bool visited[MAX_NODES];

int trace(int start)
{
    for (int i = 0; i < nodeCnt; i++)
        visited[i] = false;

    int cur = start;
    int length = 0;
    while (true)
    {
        if (visited[network[cur]])
        {
            cache[start] = length;
            return length;
        }

        if (cache[cur] != -1)
        {
            cache[start] = length + cache[cur] - 1;
            return length + cache[cur] - 1;
        }

        visited[network[cur]] = true;
        cur = network[cur];
        length++;
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
    for (int i = nodeCnt - 1; i >= 0; i--)
    {
        int newMax = trace(i);
        if (newMax >= max)
        {
            max = newMax;
            bestStart = i;
        }
    }

    return bestStart;
}

// time limit
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
