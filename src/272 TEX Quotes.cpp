#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    bool isEnded = true;
    string str;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '"')
            {
                if (isEnded) printf("``");
                else printf("''");
                isEnded = !isEnded;
            }
            else
                putchar(str[i]);
        }
        putchar('\n');
    }
}

/*

"To be or not to be," quoth the Bard, "that
is the question".
The programming contestant replied: "I must disagree.
To `C' or not to `C', that is The Question!"

``To be or not to be,'' quoth the Bard, ``that
is the question''.
The programming contestant replied: ``I must disagree.
To `C' or not to `C', that is The Question!''

*/
