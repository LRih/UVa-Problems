#include <cstdio>
#include <cstdlib>

using namespace std;

int stacks[50];

int main()
{
    int test = 1;
    while (true)
    {
        int n;
        scanf("%d", &n);
        if (n == 0) break;

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &stacks[i]);
            sum += stacks[i];
        }

        int height = sum / n;

        int moves = 0;
        for (int i = 0; i < n; i++)
            moves += abs(stacks[i] - height);

        printf("Set #%d\n", test);
        printf("The minimum number of moves is %d.\n\n", moves / 2);

        test++;
    }
}

/*

6
5 2 4 1 7 5
0

Set #1
The minimum number of moves is 5.

*/
