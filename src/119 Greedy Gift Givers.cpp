#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct person
{
    string name;
    int startMoney, give, receive;
    vector<string> recipients;
};

vector<person> people;

int getIndex(string name)
{
    for (int i = 0; i < people.size(); i++)
        if (name.compare(people[i].name) == 0) return i;
    return -1;
}

int main()
{
    int testNo = 0;
    int pplCnt;
    while (scanf("%d", &pplCnt) == 1)
    {
        people.clear();

        for (int i = 0; i < pplCnt; i++)
        {
            char name[15];
            scanf("%s", name);

            vector<string> v;
            person p = { name, 0, 0, 0, v };
            people.push_back(p);
        }

        getchar();

        for (int i = 0; i < pplCnt; i++)
        {
            char name[15];
            scanf("%s", name);

            int index = getIndex(name);
            scanf("%d", &people[index].startMoney);

            int receiveCnt;
            scanf("%d", &receiveCnt);
            for (int j = 0; j < receiveCnt; j++)
            {
                char receiverName[15];
                scanf("%s", receiverName);
                people[index].recipients.push_back(receiverName);
            }

            getchar();
        }

        // give money
        for (int i = 0; i < people.size(); i++)
        {
            vector<string> recipients = people[i].recipients;
            if (recipients.size() == 0) continue;

            int money = people[i].startMoney / recipients.size();
            people[i].give += money * recipients.size();

            for (int j = 0; j < recipients.size(); j++)
            {
                int index = getIndex(recipients[j]);
                people[index].receive += money;
            }
        }

        // print output
        if (testNo > 0) putchar('\n');
        for (int i = 0; i < people.size(); i++)
        {
            cout << people[i].name << " ";
            printf("%d\n", people[i].receive - people[i].give);
        }

        testNo++;
    }
}

/*

5
dave laura owen vick amr
dave 200 3 laura owen vick
owen 500 1 dave
amr 150 2 vick owen
laura 0 2 amr vick
vick 0 0
3
liz steve dave
liz 30 1 steve
steve 55 2 liz dave
dave 0 2 steve liz

dave 302
laura 66
owen -359
vick 141
amr -150

liz -3
steve -24
dave 27

*/
