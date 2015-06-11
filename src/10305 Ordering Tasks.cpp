#include <cstdio>
#include <cstring>
#define MAX_TASKS 100

using namespace std;

int taskCnt;
bool tasks[MAX_TASKS][MAX_TASKS];
bool done[MAX_TASKS];

bool canDo(int task)
{
    if (done[task]) return false;
    for (int i = 0; i < taskCnt; i++)
        if (tasks[task][i] && !done[i]) return false;
    return true;
}

int doTask()
{
    for (int i = 0; i < taskCnt; i++)
    {
        if (canDo(i))
        {
            done[i] = true;
            return i;
        }
    }
    return -1;
}

int main()
{
    while (true)
    {
        int edgeCnt;
        scanf("%d %d", &taskCnt, &edgeCnt);
        if (taskCnt == 0 && edgeCnt == 0) break;

        for (int i = 0; i < taskCnt; i++)
            for (int j = 0; j < taskCnt; j++)
                tasks[i][j] = false;
        memset(done, 0, sizeof(done));

        for (int i = 0; i < edgeCnt; i++)
        {
            int n1, n2;
            scanf("%d %d", &n1, &n2);
            tasks[n2 - 1][n1 - 1] = true;
        }

        for (int i = 0; i < taskCnt; i++)
        {
            if (i > 0) putchar(' ');
            printf("%d", doTask() + 1);
        }
        putchar('\n');
    }
}

/*

5 4
1 2
2 3
1 3
1 5
0 0

1 4 2 5 3

*/
