#include <cstdio>
#define COIN_CNT 5
#define MAX_VALUE 7489

using namespace std;

int coins[] = { 50, 25, 10, 5, 1 };

long long cache[COIN_CNT][MAX_VALUE + 1];

long long count(int start, int value)
{
    // invalid solution
    if (value < 0) return 0;

    // accepted solution
    if (value == 0) return 1;

    // equal to no. solutions containing start + no. solutions not containing start
    int x = 0, y = 0;

    int newVal = value - coins[start];
    if (newVal >= 0)
    {
        if (cache[start][newVal] == -1) cache[start][newVal] = count(start, newVal);
        x = cache[start][newVal];
    }

    if (start + 1 != COIN_CNT)
    {
        if (cache[start + 1][value] == -1) cache[start + 1][value] = count(start + 1, value);
        y = cache[start + 1][value];
    }

    return x + y;
}

void dp()
{
    for (int i = 0; i <= MAX_VALUE; i++)
        for (int j = 0; j < COIN_CNT; j++)
            cache[j][i] = -1;

    for (int i = 0; i <= MAX_VALUE; i++)
        for (int j = 0; j < COIN_CNT; j++)
            cache[j][i] = count(j, i);
}

int main()
{
    int n;

    dp();

    while (scanf("%d", &n) == 1)
        printf("%lld\n", cache[0][n]);
}

/*

11
26

4
13

*/
