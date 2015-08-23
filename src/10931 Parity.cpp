#include <cstdio>
#define MAX_LEN 40

using namespace std;

int binary[MAX_LEN];

int main()
{
    while (true)
    {
        int n;
        scanf("%d", &n);
        if (n == 0) break;

        int ones = 0;
        int i = 0;

        while (n != 0)
        {
            binary[i] = n % 2;
            ones += n % 2;
            n /= 2;
            i++;
        }

        printf("The parity of ");

        for (i -= 1; i >= 0; i--)
            printf("%d", binary[i]);

        printf(" is %d (mod 2).\n", ones);
    }
}

/*

1
2
10
21
0

The parity of 1 is 1 (mod 2).
The parity of 10 is 1 (mod 2).
The parity of 1010 is 2 (mod 2).
The parity of 10101 is 3 (mod 2).

*/
