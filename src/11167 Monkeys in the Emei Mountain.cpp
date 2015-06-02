#include <cstdio>
#include <vector>

using namespace std;

struct monkey
{
    int thirst;
    vector<int> times;
};

int monkeyCnt, drinkSpace;
vector<monkey> monkeys;

int main()
{
    int test = 1;
    while (scanf("%d %d", &monkeyCnt, &drinkSpace) == 2)
    {
        monkeys.clear();

        for (int i = 0; i < monkeyCnt; i++)
        {
            int start, end;
            monkey m;
            scanf("%d %d %d", &m.thirst, &start, &end);
            for (int j = start; j < end; j++)
                m.times.push_back(j);
            monkeys.push_back(m);
        }

        for (int i = 0; i < monkeys.size(); i++)
        {
            printf("%d: ", monkeys[i].thirst);
            for (int j = 0; j < monkeys[i].times.size(); j++)
                printf("%d ", monkeys[i].times[j]);
            putchar('\n');
        }
    }
}

/*

3 1
2 2 9
2 3 5
3 5 8
2 1
4 5 9
4 8 12
5 2
2 1 3
2 3 5
2 5 7
2 1 7
4 2 6
0

Case 1: Yes
2 (2,3) (8,9)
1 (3,5)
1 (5,8)
Case 2: No
Case 3: Yes
1 (1,3)
1 (3,5)
1 (5,7)
2 (1,2) (6,7)
1 (2,6)

*/
