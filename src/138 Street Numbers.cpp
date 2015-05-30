#include <stdio.h>

using namespace std;

long sum(long min, long max)
{
    return (max * (max + 1) - min * (min - 1)) / 2;
}

int main()
{
    long houseNum = 2;
    for (int i = 0; i < 10; i++)
    {
        long endNum = houseNum + 1;
        long sum1 = sum(1, houseNum - 1);
        long sum2 = sum(houseNum + 1, endNum);

        while (true)
        {
            if (sum1 == sum2)
            {
                printf("%10lu %9lu\n", houseNum, endNum);
                break;
            }
            else if (sum2 > sum1)
            {
                sum1 += houseNum;
                houseNum++;
                sum2 -= houseNum;
                while (sum2 > sum1)
                {
                    sum2 -= endNum;
                    endNum--;
                }
                continue;
            }

            endNum++;
            sum2 += endNum;
        }

        houseNum++;
    }
}