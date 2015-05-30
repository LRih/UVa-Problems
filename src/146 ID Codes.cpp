#include <stdio.h>

using namespace std;

// unfinished
int main()
{
    char id[51];
    while (true)
    {
        scanf("%s", id);
        if (id[0] == '#') break;

        printf("%s\n", id);
    }
}
