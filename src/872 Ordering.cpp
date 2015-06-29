#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define MAX_CHARS 20

using namespace std;

struct cons
{
    char c1, c2;
};

int charCnt;
char chars[MAX_CHARS];
char charsTmp[MAX_CHARS];
bool visited[MAX_CHARS];
vector<cons> constraints;
int permCnt;

bool isAllVisited()
{
    for (int i = 0; i < charCnt; i++)
        if (!visited[i]) return false;
    return true;
}

bool isMeetConstraints()
{
    for (int i = 0; i < constraints.size(); i++)
    {
        cons p = constraints[i];
        bool found1 = false;
        for (int j = 0; j < charCnt; j++)
        {
            if (charsTmp[j] == p.c1) found1 = true;
            else if (charsTmp[j] == p.c2 && !found1) return false;
        }
    }
    return true;
}

void listPerm(int index)
{
    if (isAllVisited())
    {
        if (isMeetConstraints())
        {
            for (int i = 0; i < charCnt; i++)
            {
                if (i > 0) putchar(' ');
                putchar(charsTmp[i]);
            }
            putchar('\n');
            permCnt++;
        }
        return;
    }

    for (int i = 0; i < charCnt; i++)
    {
        if (visited[i]) continue;

        charsTmp[index] = chars[i];
        visited[i] = true;
        listPerm(index + 1);
        visited[i] = false;
    }
}

int main()
{
    int tests;
    scanf("%d", &tests);

    for (int t = 0; t < tests; t++)
    {
        constraints.clear();

        getchar();
        getchar();

        charCnt = 0;
        while(true)
        {
            scanf("%c", &chars[charCnt]);
            charCnt++;
            if (cin.peek() == ' ') getchar();
            else if (cin.peek() == '\n') break;
        }
        getchar();

        while (true)
        {
            char c1, c2;
            scanf("%c<%c", &c1, &c2);

            cons p = { c1, c2 };
            constraints.push_back(p);
            if (cin.peek() == ' ') getchar();
            else if (cin.peek() == '\n') break;
        }

        if (t > 0) putchar('\n');
        permCnt = 0;
        memset(visited, 0, sizeof(visited));
        listPerm(0);
        if (permCnt == 0) printf("NO\n");
    }
}

/*

1

A B F G
A<B B<F

A B F G
A B G F
A G B F
G A B F

*/
