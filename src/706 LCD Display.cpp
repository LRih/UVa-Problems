#include <stdio.h>
#include <string.h>

using namespace std;

int s;
char num[10];

void print(int row)
{
    for (int i = 0; i < strlen(num); i++)
    {
        if (i > 0) putchar(' ');
        if ((row == 1 || row == 3 || row == 5) &&
            (num[i] == '2' || num[i] == '3' || num[i] == '5' || num[i] == '6' || num[i] == '8' ||
            num[i] == '9'))
        {
            putchar(' ');
            for (int j = 0; j < s; j++) putchar('-');
            putchar(' ');
        }
        else if (row == 1 && (num[i] == '7' || num[i] == '0'))
        {
            putchar(' ');
            for (int j = 0; j < s; j++) putchar('-');
            putchar(' ');
        }
        else if (row == 2 && (num[i] == '1' || num[i] == '2' || num[i] == '3' || num[i] == '7'))
        {
            putchar(' ');
            for (int j = 0; j < s; j++) putchar(' ');
            putchar('|');
        }
        else if (row == 2 && (num[i] == '5' || num[i] == '6'))
        {
            putchar('|');
            for (int j = 0; j < s; j++) putchar(' ');
            putchar(' ');
        }
        else if (row == 2 && (num[i] == '4' || num[i] == '8' || num[i] == '9'))
        {
            putchar('|');
            for (int j = 0; j < s; j++) putchar(' ');
            putchar('|');
        }
        else if (row == 2 && num[i] == '0')
        {
            putchar('|');
            for (int j = 0; j < s; j++) putchar(' ');
            putchar('|');
        }
        else if (row == 3 && num[i] == '4')
        {
            putchar(' ');
            for (int j = 0; j < s; j++) putchar('-');
            putchar(' ');
        }
        else if (row == 4 && num[i] == '2')
        {
            putchar('|');
            for (int j = 0; j < s; j++) putchar(' ');
            putchar(' ');
        }
        else if (row == 4 && (num[i] == '1' || num[i] == '3' || num[i] == '4' || num[i] == '5' ||
            num[i] == '7' || num[i] == '9'))
        {
            putchar(' ');
            for (int j = 0; j < s; j++) putchar(' ');
            putchar('|');
        }
        else if (row == 4 && (num[i] == '6' || num[i] == '8' || num[i] == '0'))
        {
            putchar('|');
            for (int j = 0; j < s; j++) putchar(' ');
            putchar('|');
        }
        else if (row == 5 && num[i] == '0')
        {
            putchar(' ');
            for (int j = 0; j < s; j++) putchar('-');
            putchar(' ');
        }
        else
            for (int j = 0; j < s + 2; j++) putchar(' ');
    }
    putchar('\n');
}

int main()
{
    while (true)
    {
        scanf("%d %s", &s, num);
        if (s == 0 && num[0] == '0') break;

        print(1);
        for (int i = 0; i < s; i++) print(2);
        print(3);
        for (int i = 0; i < s; i++) print(4);
        print(5);
        putchar('\n');
    }
}

/*

2 12345
3 67890
0 0

      --   --        -- 
   |    |    | |  | |   
   |    |    | |  | |   
      --   --   --   -- 
   | |       |    |    |
   | |       |    |    |
      --   --        -- 

 ---   ---   ---   ---   --- 
|         | |   | |   | |   |
|         | |   | |   | |   |
|         | |   | |   | |   |
 ---         ---   ---       
|   |     | |   |     | |   |
|   |     | |   |     | |   |
|   |     | |   |     | |   |
 ---         ---   ---   --- 

 */
