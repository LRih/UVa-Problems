#include <cstdio>

using namespace std;

// time limit
int main()
{
    int n, k;
    while (scanf("%d %d", &n, &k) == 2)
    {
        int butts = n;
        while (butts >= k)
        {
            int add = butts / k;
            n += add;
            butts += add;
            butts -= add * k;
        }
        printf("%d\n", n);
    }
}

/*

4 3
10 3
100 5

5
14
124

*/
