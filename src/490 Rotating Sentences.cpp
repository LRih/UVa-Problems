#include <stdio.h>
#include <iostream>

using namespace std;

int count = 0;
string sentences[100];

int longestStr()
{
    int longest = 0;
    for (int i = 0; i < count; i++)
        if (sentences[i].length() > longest)
            longest = sentences[i].length();
    return longest;
}

// runtime error
int main()
{
    while (getline(cin, sentences[count]))
        count++;

    int longest = longestStr();
    for (int i = 0; i < longest; i++)
    {
        for (int j = 0; j < count; j++)
        {
            string str = sentences[count - j - 1];
            if (i >= str.length()) printf(" ");
            else printf("%c", str.at(i));
            
        }
        printf("\n");
    }
}

/*

Rene Decartes once said,
"I think, therefore I am."

"R
Ie
 n
te
h 
iD
ne
kc
,a
 r
tt
he
es
r
eo
fn
oc
re
e
 s
Ia
 i
ad
m,
.
"

*/
