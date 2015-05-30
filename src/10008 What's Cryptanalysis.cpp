#include <stdio.h>
#include <cstdlib>
#include <cctype>

using namespace std;

int counts[26][2];
char text[1000];

int cmp(const void* a, const void* b)
{
    const int* o1 = (int*)a;
    const int* o2 = (int*)b;

    if (o1[1] < o2[1]) return 1;
    if (o1[1] > o2[1]) return -1;

    if (o1[0] < o2[0]) return -1;
    if (o1[0] > o2[0]) return 1;

    return 1;
}

int main()
{
    for (int i = 0; i < 26; i++)
    {
        counts[i][0] = i;
        counts[i][1] = 0;
    }

    int n;
    scanf("%d\n", &n);

    int linesRead = 0;
    for (int i = 0; linesRead < n; i++)
    {
        char c = toupper(getchar());
        if (c >= 65 && c <= 90)
            counts[c - 65][1]++;
            if (c == '\n') linesRead++;
    }

    qsort(counts, 26, sizeof(int) * 2, cmp);

    for (int i = 0; i < 26; i++)
        if (counts[i][1] > 0)
            printf("%c %d\n", counts[i][0] + 65, counts[i][1]);
}

/*

3
This is a test.
Count me 1 2 3 4 5.
Wow!!!! Is this question easy?

S 7
T 6
I 5
E 4
O 3
A 2
H 2
N 2
U 2
W 2
C 1
M 1
Q 1
Y 1

*/
