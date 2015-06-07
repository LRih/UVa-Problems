#include <cstdio>
#include <iostream>

using namespace std;

int getWordEnd(string str, int start)
{
    while (start < str.length() && str[start] != ' ')
        start++;
    return start - 1;
}

int main()
{
    string str;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.length(); i++)
        {
            int end = getWordEnd(str, i);

            for (int j = i; j <= i + (end - i) / 2; j++)
            {
                char tmp = str[j];
                str[j] = str[end - (j - i)];
                str[end - (j - i)] = tmp;
            }

            i = end + 1;
        }

        cout << str << endl;
    }
}

/*

I love you.
You love me.
We're a happy family.

I evol .uoy
uoY evol .em
er'eW a yppah .ylimaf

*/
