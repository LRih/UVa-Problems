#include <cstdio>
#include <iostream>

using namespace std;

string str;

int getNum()
{
    if (str.length() == 5) return 3;

    int one = 0, two = 0;

    if (str[0] == 'o') one++;
    else if (str[0] == 't') two++;

    if (str[1] == 'n') one++;
    else if (str[1] == 'w') two++;

    if (str[2] == 'e') one++;
    else if (str[2] == 'o') two++;

    return one > two ? 1 : 2;
}

int main()
{
    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        printf("%d\n", getNum());
    }
}

/*

3
owe
too
theee

1
2
3

*/
