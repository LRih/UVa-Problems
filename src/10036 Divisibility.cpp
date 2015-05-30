#include <stdio.h>

using namespace std;

int numCount, div;
int numbers[10000];
int operators[10000];

bool checkDivisibility(int index)
{
    if (index == numCount - 1)
    {
        int sum = numbers[0];
        for (int i = 1; i < numCount; i++)
        {
            if (operators[i - 1] == 1) sum += numbers[i];
            else sum -= numbers[i];
        }
        return (sum % div == 0);
    }

    for (int j = 1; j <= 2; j++)
    {
        operators[index] = j;
        if (checkDivisibility(index + 1)) return true;
    }
    return false;
}

// time limit exceeded
int main()
{
    int count;
    scanf("%d", &count);

    for (int i = 0; i < count; i++)
    {
        scanf("%d", &numCount);
        scanf("%d", &div);

        for (int j = 0; j < numCount; j++)
        {
            scanf("%d", &numbers[j]);
            operators[j] = 0;
        }

        if (checkDivisibility(0)) printf("Divisible\n");
        else printf("Not divisible\n");
    }
}

/*

2
4 7
17 5 -21 15
4 5
17 5 -21 15

Divisible
Not divisible

*/
