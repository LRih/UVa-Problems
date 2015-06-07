#include <cstdio>

using namespace std;

int main()
{
    int grades[1000];

    int tests;
    scanf("%d", &tests);
    while (tests--)
    {
        int gradeCnt;
        scanf("%d", &gradeCnt);

        double avg = 0;
        for (int i = 0; i < gradeCnt; i++)
        {
            scanf("%d", &grades[i]);
            avg += grades[i];
        }
        avg /= gradeCnt;

        int above = 0;        
        for (int i = 0; i < gradeCnt; i++)
            if (grades[i] > avg) above++;

        printf("%.3f%%\n", above / (double)gradeCnt * 100);
    }
}

/*

5
5 50 50 70 80 100
7 100 95 90 80 70 60 50
3 70 90 80
3 70 90 81
9 100 99 98 97 96 95 94 93 91

40.000%
57.143%
33.333%
66.667%
55.556%

*/
