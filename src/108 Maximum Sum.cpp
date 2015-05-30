#include <stdio.h>

using namespace std;

int n;
int grid[100][100];

int getSum(int oi, int oj, int ei, int ej)
{
    int sum = 0;
    for (int i = oi; i <= ei; i++)
        for (int j = oj; j <= ej; j++)
            sum += grid[i][j];
    return sum;
}

// time limit exceeded
int main()
{
    // use kadane algorithm

    bool started = false;
    int sum = 0;

    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         scanf("%d", &grid[i][j]);

    // worst case
    n = 100;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            grid[i][j] = i * j;


    for (int oi = 0; oi < n; oi++)
    {
        for (int oj = 0; oj < n; oj++)
        {
            printf("%d, %d\n", oi, oj);
            for (int ei = oi; ei < n; ei++)
            {
                for (int ej = oj; ej < n; ej++)
                {
                    int newSum = getSum(oi, oj, ei, ej);
                    if (newSum > sum) sum = newSum;
                }
            }
        }
    }

    printf("%d\n", sum);
}

/*

4
0 -2 -7  0 9  2 -6  2
-4  1 -4  1 -1
8  0 -2

15

*/