#include <cstdio>
#include <cmath>
#define MAX_START 25
#define MAX_VALUE 10000

using namespace std;

long long cache[MAX_START + 1][MAX_VALUE + 1];

long long count(int start, int value)
{
    // invalid solution
    if (value < 0) return 0;

    // accepted solution
    if (value == 0) return 1;

    int newVal = value - (int)pow(start, 3);
    if (newVal < 0) return 0;

    // equal to no. solutions containing start + no. solutions not containing start
    if (cache[start][newVal] == -1)
        cache[start][newVal] = count(start, newVal);
    if (cache[start + 1][value] == -1)
        cache[start + 1][value] = count(start + 1, value);

    return cache[start][newVal] + cache[start + 1][value];
}

void dp()
{
    for (int i = 0; i <= MAX_VALUE; i++)
        for (int j = 0; j <= MAX_START; j++)
            cache[j][i] = -1;

    for (int i = 0; i <= MAX_VALUE; i++)
        for (int j = MAX_START; j >= 1; j--)
            cache[j][i] = count(j, i);
}

// wrong answer
int main()
{
    int n;

    dp();

    while (scanf("%d", &n) == 1)
        printf("%lld\n", cache[1][n]);
}

/*

10
21
77
9999

2
3
22
440022018293

*/
