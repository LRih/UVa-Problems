#include <stdio.h>

using namespace std;

char str[10];
int n;

int getBinaryOnes(int num)
{
    int count = 0;
    while (num != 0)
    {
        count += num % 2;
        num /= 2;
    }
    return count;
}

int getHexBinaryOnes()
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        count += getBinaryOnes(str[i] - 48);
    return count;
}

int main()
{
    int cnt;
    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++)
    {
        scanf("%s", str);
        sscanf(str, "%d", &n);

        printf("%d %d\n", getBinaryOnes(n), getHexBinaryOnes());
    }
}

/*

3
265
111
1234

3 5
6 3
5 5

*/