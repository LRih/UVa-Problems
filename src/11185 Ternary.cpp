#include <cstdio>

using namespace std;

int arr[20];

int main()
{
    while (true)
    {
        int n;
        scanf("%d", &n);
        if (n < 0) break;

        int len = 0;
        if (n == 0)
        {
            arr[0] = 0;
            len = 1;
        }
        else
        {
            while (n != 0)
            {
                arr[len] = n % 3;
                n /= 3;
                len++;
            }
        }

        for (int i = len - 1; i >= 0; i--)
            printf("%d", arr[i]);

        printf("\n");
    }
}

/*

10
100
1000
-1

101
10201
1101001

*/
