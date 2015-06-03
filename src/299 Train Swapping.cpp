#include <cstdio>

using namespace std;

int bubbleSort(int array[], int size)
{
    int swaps = 0;
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                swaps++;
            }
        }
    }
    return swaps;
}

int main()
{
    int testCnt;
    scanf("%d", &testCnt);
    while (testCnt--)
    {
        int size;
        int array[50];
        scanf("%d", &size);
        for (int i = 0; i < size; i++)
            scanf("%d", &array[i]);

        printf("Optimal train swapping takes %d swaps.\n", bubbleSort(array, size));
    }
}

/*

3
3
1 3 2
4
4 3 2 1
2
2 1

Optimal train swapping takes 1 swaps.
Optimal train swapping takes 6 swaps.
Optimal train swapping takes 1 swaps.

*/
