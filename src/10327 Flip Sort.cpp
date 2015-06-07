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
    int size;
    int array[1000];
    while (scanf("%d", &size) == 1)
    {
        for (int i = 0; i < size; i++)
            scanf("%d", &array[i]);

        printf("Minimum exchange operations : %d\n", bubbleSort(array, size));
    }
}

/*

3
1 2 3
3
2 3 1

Minimum exchange operations : 0
Minimum exchange operations : 2

*/
