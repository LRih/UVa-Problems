#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define MAX_WORDS 200
#define WORD_LEN 15

using namespace std;

int wordCnt;
char words[MAX_WORDS][WORD_LEN];
bool visited[MAX_WORDS];
int start, end;

struct agent
{
    int index, steps;
};

bool isConnected(char w1[], char w2[])
{
    int len = strlen(w1);
    if (len != strlen(w2)) return false;

    int difCnt = 0;
    for (int i = 0; i < len; i++)
        if (w1[i] != w2[i]) difCnt++;
    return difCnt == 1;
}

int findPath()
{
    memset(visited, 0, sizeof(visited));

    agent s = { start, 0 };

    queue<agent> q;
    q.push(s);

    while (!q.empty())
    {
        agent cur = q.front(); q.pop();

        if (strcmp(words[cur.index], words[end]) == 0) return cur.steps;

        if (visited[cur.index]) continue;

        for (int i = 0; i < wordCnt; i++)
        {
            if (isConnected(words[cur.index], words[i]))
            {
                agent next = { i, cur.steps + 1 };
                q.push(next);
                visited[cur.index] = true;
            }
        }
    }

    return -1;
}

// runtime error
int main()
{
    int testCnt = 0;
    scanf("%d", &testCnt);
    getchar();
    for (int t = 0; t < testCnt; t++)
    {
        getchar();

        wordCnt = 0;
        while (true)
        {
            scanf("%s", words[wordCnt]);
            if (words[wordCnt][0] == '*') break;
            wordCnt++;
        }
        getchar();

        while (true)
        {
            char s[WORD_LEN], e[WORD_LEN];
            scanf("%s %s", s, e);

            for (int i = 0; i < wordCnt; i++)
            {
                if (strcmp(s, words[i]) == 0) start = i;
                if (strcmp(e, words[i]) == 0) end = i;
            }
            getchar();

            if (testCnt > 0) putchar('\n');
            printf("%s %s %d\n", s, e, findPath());

            if (cin.peek() == '\n' || cin.peek() == EOF)
                break;
        }
    }
}

/*

1

dip
lip
mad
map
maple
may
pad
pip
pod
pop
sap
sip
slice
slick
spice
stick
stock
*
spice stock
may pod

spice stock 4
may pod 3

*/
