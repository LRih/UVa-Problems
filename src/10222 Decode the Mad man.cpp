#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    string str;
    getline(cin, str);

    for (int i = 0; i < str.length(); i++)
    {
        char c;
        switch (tolower(str[i]))
        {
            case 'e' : c = 'q'; break;
            case 'r' : c = 'w'; break;
            case 't' : c = 'e'; break;
            case 'y' : c = 'r'; break;
            case 'u' : c = 't'; break;
            case 'i' : c = 'y'; break;
            case 'o' : c = 'u'; break;
            case 'p' : c = 'i'; break;
            case '[' : case '{' : c = 'o'; break;
            case ']' : case '}' : c = 'p'; break;

            case 'd' : c = 'a'; break;
            case 'f' : c = 's'; break;
            case 'g' : c = 'd'; break;
            case 'h' : c = 'f'; break;
            case 'j' : c = 'g'; break;
            case 'k' : c = 'h'; break;
            case 'l' : c = 'j'; break;
            case ':' : case ';' : c = 'k'; break;
            case '"' : case '\'' : c = 'l'; break;
            
            case 'c' : c = 'z'; break;
            case 'v' : c = 'x'; break;
            case 'b' : c = 'c'; break;
            case 'n' : c = 'v'; break;
            case 'm' : c = 'b'; break;
            case '<' : case ',' : c = 'n'; break;
            case '>' : case '.' : c = 'm'; break;

            default: c = ' ';
        }
        printf("%c", c);
    }
    printf("\n");
}

/*

k[r dyt I[o

how are you

*/
