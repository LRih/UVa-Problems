#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int counts[130];

int main()
{
    string str;
    while (getline(cin, str))
    {
        memset(counts, 0, sizeof(counts));

        for (int i = 0; i < str.length(); i++)
            if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
                counts[str[i]]++;

        int max = 0;
        for (int i = 65; i <= 90; i++)
            if (counts[i] > max) max = counts[i];
        for (int i = 97; i <= 122; i++)
            if (counts[i] > max) max = counts[i];

        for (int i = 65; i <= 90; i++)
            if (counts[i] == max) printf("%c", i);
        for (int i = 97; i <= 122; i++)
            if (counts[i] == max) printf("%c", i);
        printf(" %d\n", max);
    }
}

/*

When riding your bicycle backwards down a one-way street, if the
wheel falls of a canoe, how many ball bearings does it take to fill
up a water buffalo?
Hello Howard.

e 6
al 7
a 3
Hlo 2

*/
