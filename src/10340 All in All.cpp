#include <cstdio>
#include <iostream>

using namespace std;

int secondStart(string str)
{
    for (int i = 0; i < str.length(); i++)
        if (str[i] == ' ') return i + 1;
    return -1;
}

bool isContained(string str)
{
    int j = secondStart(str);

    for (int i = 0; str[i] != ' '; i++)
    {
        while (j < str.length())
        {
            if (str[j] == str[i]) break;
            else j++;
        }
        if (j >= str.length()) return false;
        j++;
    }
    return true;
}

int main()
{
    string str;
    while (getline(cin, str))
    {
        if (isContained(str)) printf("Yes\n");
        else printf("No\n");
    }
}

/*

sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter

Yes
No
Yes
No

*/
