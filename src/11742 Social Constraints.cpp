#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#define MAX_GROUP 8

using namespace std;

struct cons
{
    int p1, p2, dist;
};

int groupCnt;
int group[MAX_GROUP];
bool visited[MAX_GROUP];
vector<cons> constraints;
int permCnt;

bool isMeetConstraints()
{
    for (int i = 0; i < constraints.size(); i++)
    {
        cons p = constraints[i];
        int index1, index2;

        for (index1 = 0; group[index1] != p.p1; index1++);
        for (index2 = 0; group[index2] != p.p2; index2++);

        if (p.dist > 0)
        {
            if (abs(index1 - index2) > p.dist) return false;
        }
        else
        {
            if (abs(index1 - index2) < abs(p.dist)) return false;
        }
    }
    return true;
}

void listPerm(int index)
{
    if (index == groupCnt)
    {
        if (isMeetConstraints())
            permCnt++;
        return;
    }

    for (int i = 0; i < groupCnt; i++)
    {
        if (visited[i]) continue;

        group[index] = i;
        visited[i] = true;
        listPerm(index + 1);
        visited[i] = false;
    }
}

int main()
{
    while (true)
    {
        int consCount;
        scanf("%d %d", &groupCnt, &consCount);
        if (groupCnt == 0 && consCount == 0) break;

        constraints.clear();
        memset(visited, 0, sizeof(visited));
        permCnt = 0;

        for (int i = 0; i < consCount; i++)
        {
            int p1, p2, dist;
            scanf("%d %d %d", &p1, &p2, &dist);

            cons c = { p1, p2, dist };
            constraints.push_back(c);
        }

        listPerm(0);
        printf("%d\n", permCnt);
    }

}

/*

3 1
0 1 -2
3 0
0 0

2
6

*/
