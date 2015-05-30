#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int amp, freq;
        scanf("%d", &amp);
        scanf("%d", &freq);

        for (int f = 0; f < freq; f++)
        {
            for (int a = 0; a < amp; a++)
            {
                for (int j = 0; j < a + 1; j++) printf("%d", a + 1);
                printf("\n");
            }
            for (int a = amp - 1; a >= 0; a--)
            {
                for (int j = 0; j < a; j++) printf("%d", a);
                if (f != freq - 1 || a != 0) printf("\n");
            }
        }
        if (i != n - 1) printf("\n");
    }
}

/*

1

3
2

1
22
333
22
1

1
22
333
22
1

*/
