#include <stdio.h>

using namespace std;

int num[20];
int result[20];

int numLen()
{
    for (int i = 0;; i++)
        if (num[i] == -1) return i;
    return -1;
}

int resLen()
{
    for (int i = 0;; i++)
        if (result[i] == -1) return i;
    return -1;
}

int sum()
{
    int carry = 0;
    int len = numLen();

    for (int i = 0; i < len; i++)
    {
        int add = num[i] + num[len - i - 1];
        if (carry == 1)
        {
            add++;
            carry = 0;
        }

        if (add >= 10)
            carry = 1;
        result[i] = add % 10;
    }

    if (carry == 1)
        result[len] = 1;
}

void moveResultToNum()
{
    int len = resLen();

    for (int i = 0; i < len; i++)
        num[i] = result[i];
}

bool isResultPalindrome()
{
    int len = resLen();
    for (int i = 0; i < len; i++)
        if (result[i] != result[len - i - 1]) return false;
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < 20; i++)
        {
            num[i] = -1;
            result[i] = -1;
        }

        char input[20];
        scanf("%s", input);
        for (int i = 0; input[i] != '\0'; i++)
            num[i] = input[i] - 48;

        int times = 0;
        do
        {
            sum();
            moveResultToNum();
            times++;
        } while (!isResultPalindrome());

        printf("%d ", times);
        for (int i = 0; result[i] != -1; i++)
            printf("%d", result[i]);
        printf("\n");
    }
}

/*

3
195
265
750

4 9339
5 45254
3 6666

*/
