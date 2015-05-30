#include <stdio.h>
#include <ctype.h>
#include <iostream>

using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        int words = 0;
        bool wordStart = false;
        for (int i = 0; i < str.length(); i++)
        {
            char c = toupper(str.at(i));
            if (!wordStart)
            {
                if (c >= 65 && c <= 90)
                {
                    wordStart = true;
                    words++;
                }
            }
            else
            {
                if (!(c >= 65 && c <= 90))
                    wordStart = false;
            }
        }
        if (wordStart) words++;

        printf("%d\n", words);
    }
}

/*

Meep Meep!
I tot I taw a putty tat.
I did! I did! I did taw a putty tat.
Shsssssssssh ... I am hunting wabbits. Heh Heh Heh Heh ...

2
7
10
9

*/
