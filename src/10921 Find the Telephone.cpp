#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    string str;

    while (getline(cin, str))
    {
        for (int i = 0; i < str.length(); i++)
        {
            switch (str[i])
            {
                case 'A': case 'B': case 'C':
                    putchar('2'); break;
                case 'D': case 'E': case 'F':
                    putchar('3'); break;
                case 'G': case 'H': case 'I':
                    putchar('4'); break;
                case 'J': case 'K': case 'L':
                    putchar('5'); break;
                case 'M': case 'N': case 'O':
                    putchar('6'); break;
                case 'P': case 'Q': case 'R': case 'S':
                    putchar('7'); break;
                case 'T': case 'U': case 'V':
                    putchar('8'); break;
                case 'W': case 'X': case 'Y': case 'Z':
                    putchar('9'); break;
                default:
                    printf("%c", str[i]); break;
            }
        }
        putchar('\n');
    }
}

/*

1-HOME-SWEET-HOME
MY-MISERABLE-JOB

1-4663-79338-4663
69-647372253-562

*/
