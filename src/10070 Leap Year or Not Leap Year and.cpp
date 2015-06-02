#include <cstdio>
#include <iostream>

using namespace std;

string year;

bool isDiv3()
{
    unsigned long sum = 0;
    for (int i = 0; i < year.length(); i++)
        sum += year.at(i) - 48;
    return sum % 3 == 0;
}

bool isDiv4()
{
    int num = (year.at(year.length() - 2) - 48) * 10 + year.at(year.length() - 1) - 48;
    return num % 4 == 0;
}

bool isDiv5()
{
    int num = year.at(year.length() - 1) - 48;
    return num == 0 || num == 5;
}

bool isDiv11()
{
    long sum = 0;
    for (int i = 0; i < year.length(); i++)
    {
        if (i % 2 == 0) sum += year.at(i) - 48;
        else sum -= year.at(i) - 48;
    }
    return sum % 11 == 0;
}

bool isDiv15()
{
    return isDiv3() && isDiv5();
}

bool isDiv55()
{
    return isDiv5() && isDiv11();
}

bool isDiv100()
{
    return year.at(year.length() - 2) - 48 == 0 && year.at(year.length() - 1) - 48 == 0;
}

bool isDiv400()
{
    int num = (year.at(year.length() - 4) - 48) * 10 + (year.at(year.length() - 3) - 48);
    return num % 4 == 0 && isDiv100();
}

bool isLeap()
{
    return (isDiv4() && !isDiv100()) || isDiv400();
}

bool isHulu()
{
    return isDiv15();
}

bool isBulu()
{
    return isDiv55() && isLeap();
}

int main()
{
    int testNo = 0;
    while (getline(cin, year))
    {
        bool isL = isLeap();
        bool isH = isHulu();
        bool isB = isBulu();

        if (testNo > 0) putchar('\n');
        if (!isL && !isH && !isB) printf("This is an ordinary year.\n");
        else
        {
            if (isL) printf("This is leap year.\n");
            if (isH) printf("This is huluculu festival year.\n");
            if (isB) printf("This is bulukulu festival year.\n");
        }

        testNo++;
    }
}

/*

2000
3600
4515
2001

This is leap year.

This is leap year.
This is huluculu festival year.

This is huluculu festival year.

This is an ordinary year.

*/
