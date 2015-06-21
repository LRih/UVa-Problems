#include <cstdio>
#include <iostream>

using namespace std;

string s1, s2;

int getLock(int offset)
{
    int overlap = 0;
    for (int i = 0; i < s2.length(); i++)
    {
        int index = i - offset;
        if (index >= 0 && index < s1.length())
        {
            if (s1[index] - 48 + s2[i] - 48 <= 3) overlap++;
            else return -1;
        }
    }
    return overlap;
}

int getMin()
{
    int min = s1.length() + s2.length();

    int start = -s1.length();
    int end = s2.length();

    for (int i = start; i < end; i++)
    {
        int lock = getLock(i);
        if (lock != -1)
        {
            int span = s1.length() + s2.length() - lock;
            if (span < min) min = span;
        }
    }

    return min;
}

int main()
{
    while (getline(cin, s1))
    {
        getline(cin, s2);
        printf("%d\n", getMin());
    }
}

/*

2112112112
2212112
12121212
21212121
2211221122
21212

10
8
15

*/
