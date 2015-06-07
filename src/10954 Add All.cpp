#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    while (true)
    {
        int n;
        scanf("%d", &n);
        if (n == 0) break;

        priority_queue<int, vector<int>, greater<int> > q;

        for (int i = 0; i < n; i++)
        {
            int num;
            scanf("%d", &num);
            q.push(num);
        }

        int cost = 0;
        while (true)
        {
            int cur1 = q.top(); q.pop();
            int cur2 = q.top(); q.pop();
            cost += cur1 + cur2;

            if (q.empty()) break;
            q.push(cur1 + cur2);
        }
        printf("%d\n", cost);
    }
}

/*

3
1 2 3
4
1 2 3 4
0

9
19

*/
