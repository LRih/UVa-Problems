#include <stdio.h>

using namespace std;

int num1[20];
int num2[20];
int result[20];

int num1Len()
{
    for (int i = 0;; i++)
        if (num1[i] == -1) return i;
    return -1;
}

int num2Len()
{
    for (int i = 0;; i++)
        if (num2[i] == -1) return i;
    return -1;
}

int getCarryCount()
{
    int count = 0;
    int carry = 0;
    int len1 = num1Len();
    int len2 = num2Len();

    for (int i = 0;; i++)
    {
        if (len1 - i - 1 < 0 && len2 - i - 1 < 0)
            break;

        int add;
        if (len1 - i - 1 == -1)
            add = num2[len2 - i - 1];
        else if (len2 - i - 1 == -1)
            add = num1[len1 - i - 1];
        else
            add = num1[len1 - i - 1] + num2[len2 - i - 1];

        if (carry == 1)
        {
            add++;
            carry = 0;
        }

        if (add >= 10)
        {
            carry = 1;
            count++;
        }
        result[i] = add % 10;
    }

    return count;
}

int main()
{
    while (true)
    {
        char input1[20], input2[20];
        scanf("%s %s", input1, input2);
        if (input1[0] == '0' && input2[0] == '0' && input1[1] == '\0' && input2[1] == '\0') break;

        for (int i = 0; i < 20; i++)
        {
            num1[i] = -1;
            num2[i] = -1;
            result[i] = -1;
        }

        for (int i = 0; input1[i] != '\0'; i++)
            num1[i] = input1[i] - 48;
        for (int i = 0; input2[i] != '\0'; i++)
            num2[i] = input2[i] - 48;

        int cnt = getCarryCount();
        if (cnt == 0)
            printf("No carry operation.\n");
        else if (cnt == 1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n", cnt);
    }
}

/*

123 456
555 555
123 594
0 0

No carry operation.
3 carry operations.
1 carry operation.

*/
