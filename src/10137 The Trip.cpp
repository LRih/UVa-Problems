#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
double money[1000];

double total()
{
    double result = 0;
    for (int i = 0; i < n; i++)
        result += money[i];
    return result;
}

double doSwap(double avg)
{
    int mini = -1;
    double minMoney = 99999;
    for (int i = 0; i < n; i++)
    {
        if (money[i] < minMoney)
        {
            mini = i;
            minMoney = money[i];
        }
    }

    int max = -1;
    double maxMoney = -1;
    for (int i = 0; i < n; i++)
    {
        if (money[i] > maxMoney)
        {
            max = i;
            maxMoney = money[i];
        }
    }

    double change = min(maxMoney - avg, avg - minMoney);
    money[mini] += change;
    money[max] -= change;

    return change;
}

bool isEqual(double avg)
{
    for (int i = 0; i < n; i++)
        if (!(money[i] >= avg - (double)0.01 && money[i] <= avg + (double)0.01)) return false;
    return true;
}

// time limit exceeded
int main()
{
    while (true)
    {
        scanf("%d", &n);
        if (n == 0) break;

        double totalExchanged = 0;

        for (int i = 0; i < n; i++)
            scanf("%lf", &money[i]);

        double avg = ((int)(total() / n * 100)) / (double)100;

        while (!isEqual(avg))
            totalExchanged += doSwap(avg);

        printf("$%.2f\n", totalExchanged);
    }
}

/*

3
10.00
20.00
30.00
4
15.00
15.01
3.00
3.01
0

$10.00
$11.99

*/
