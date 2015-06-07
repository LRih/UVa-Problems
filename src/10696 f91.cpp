#include <cstdio>

using namespace std;

int f91(int n)
{
    if (n <= 100) return f91(f91(n + 11));
    else return n - 10;
}

int main()
{
    while (true)
    {
        int n;
        scanf("%d", &n);
        if (n == 0) break;

        printf("f91(%d) = %d\n", n, f91(n));
    }

}

/*

500
91
0

f91(500) = 490
f91(91) = 91

*/
