#include <cstdio>
#include <vector>
#include <queue>
#define MAX_STREETS 2000

using namespace std;

struct node
{
    int i, j;
};

struct agent
{
    int i, j, time;
};

int maxNodes;
vector<node> shop1;
vector<node> shop2;
bool visited[MAX_STREETS][MAX_STREETS];

bool inShop2(agent a)
{
    for (int i = 0; i < shop2.size(); i++)
        if (a.i == shop2[i].i && a.j == shop2[i].j) return true;
    return false;
}

int findPath()
{
    int mRow[] = { -1, 1, 0, 0 };
    int mCol[] = { 0, 0, -1, 1 };

    for (int i = 0; i < maxNodes; i++)
        for (int j = 0; j < maxNodes; j++)
            visited[i][j] = false;

    queue<agent> q;
    for (int i = 0; i < shop1.size(); i++)
    {
        agent a = { shop1[i].i, shop1[i].j, 0 };
        q.push(a);
    }

    while (!q.empty())
    {
        agent cur = q.front(); q.pop();

        if (inShop2(cur)) return cur.time;

        for (int i = 0; i < 4; i++)
        {
            int ni = cur.i + mRow[i];
            int nj = cur.j + mCol[i];

            if (ni < 0 || ni >= maxNodes || nj < 0 || nj >= maxNodes)
                continue;

            if (!visited[ni][nj])
            {
                agent next = { ni, nj, cur.time + 1 };
                q.push(next);
                visited[ni][nj] = true;
            }
        }
    }

    return -1;
}

// time limit
int main()
{
    while (true)
    {
        shop1.clear();
        shop2.clear();

        int perim;
        scanf("%d", &perim);
        for (int i = 0; i < perim; i++)
        {
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            node p = { n1, n2 };
            shop1.push_back(p);

            if (n1 > maxNodes) maxNodes = n1;
            if (n2 > maxNodes) maxNodes = n2;
        }

        scanf("%d", &perim);
        for (int i = 0; i < perim; i++)
        {
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            node p = { n1, n2 };
            shop2.push_back(p);

            if (n1 > maxNodes) maxNodes = n1;
            if (n2 > maxNodes) maxNodes = n2;
        }

        printf("%d\n", findPath());
    }
}

/*

4
0 0 0 1 1 1 1 0
6
4 3 4 2 3 2
2 2 2 3
3 3
0

2

*/
