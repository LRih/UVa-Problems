#include <cstdio>
#include <list>

using namespace std;

list<char> lst;
list<char>::iterator it;

// time limit
int main()
{
    it = lst.begin();
    while (true)
    {
        char c;
        scanf("%c", &c);

        if (c == '\n')
        {
            list<char>::iterator i;
            for (i = lst.begin(); i != lst.end(); i++)
                putchar(*i);
            putchar('\n');
            lst.clear();
            it = lst.begin();
        }
        else if (c == EOF)
            break;
        else if (c == '[')
            it = lst.begin();
        else if (c == ']')
            it = lst.end();
        else
            lst.insert(it, c);
    }
}

/*

This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University

BeijuThis_is_a__text
Happy_Birthday_to_Tsinghua_University

*/
