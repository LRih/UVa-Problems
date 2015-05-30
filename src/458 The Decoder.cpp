#include <stdio.h>

using namespace std;

int main()
{
    char msg[10000];
    while (scanf("%s", msg) == 1)
    {
        for (int i = 0; msg[i] != '\0'; i++)
            printf("%c", msg[i] - 7);
        printf("\n");
    }
}

/*

1JKJ'pz'{ol'{yhklthyr'vm'{ol'Jvu{yvs'Kh{h'Jvywvyh{pvu5
1PIT'pz'h'{yhklthyr'vm'{ol'Pu{lyuh{pvuhs'I|zpulzz'Thjopul'Jvywvyh{pvu5
1KLJ'pz'{ol'{yhklthyr'vm'{ol'Kpnp{hs'Lx|pwtlu{'Jvywvyh{pvu5

*CDC is the trademark of the Control Data Corporation.
*IBM is a trademark of the International Business Machine Corporation.
*DEC is the trademark of the Digital Equipment Corporation.

*/
