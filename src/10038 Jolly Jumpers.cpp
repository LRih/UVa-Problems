#include <cstdio>
#include <cstdlib>

using namespace std;

int n;
int numbers[3000];
bool checked[3000];

bool isJolly()
{
    for (int i = 1; i < n; i++)
    {
        int dif = abs(numbers[i] - numbers[i - 1]);
        if (dif > n - 1 || checked[dif]) return false;
        checked[dif] = true;
    }
    return true;
}

int main()
{
    while (scanf("%d", &n) == 1)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &numbers[i]);
            checked[i] = false;
        }

        if (isJolly()) printf("Jolly\n");
        else printf("Not jolly\n");
    }
}

/*

4 1 4 2 3
5 1 4 2 -1 6

Jolly
Not jolly

*/
