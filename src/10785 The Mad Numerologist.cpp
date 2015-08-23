#include <cstdio>
#include <cstdlib>
#define MAX_LEN 215

using namespace std;

char consonants[] = "JSBKTCLDMVNWFXGPYHQZR";
char vowels[] = "AUEOI";

char res1[MAX_LEN];
char res2[MAX_LEN];

int cmp(const void *a, const void *b)
{
    return *(char*)a - *(char*)b;
}

// wrong answer, needs sorting
int main()
{
    int n;
    scanf("%d", &n);

    for (int t = 0; t < n; t++)
    {
        int length;
        scanf("%d", &length);

        printf("Case %d: ", t + 1);

        for (int i = 0; i < length; i++)
        {
            if (i % 2 == 0)
                res1[i / 2] = vowels[i / 42];
            else
                res2[(i - 1) / 2] = consonants[i / 10];
        }

        res1[(length + 1) / 2] = res2[length / 2] = '\0';

        qsort(res1, (length + 1) / 2, sizeof(char), cmp);
        qsort(res2, length / 2, sizeof(char), cmp);

        for (int i = 0; i < (length + 1) / 2; i++)
        {
            printf("%c", res1[i]);
            if (res2[i] == '\0') break;
            else printf("%c", res2[i]);
        }

        printf("\n");
    }
}

/*

3
1
5
5

Case 1: A
Case 2: AJAJA
Case 3: AJAJA

*/
