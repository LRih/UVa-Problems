#include <cstdio>
#include <iostream>
#define MAX_PROGRAMS 10

using namespace std;

int jobCnt = 0;
char programs[MAX_PROGRAMS];
char jobs[26][40];

bool findAllocation(int remaining)
{
    if (remaining == 0) return true;

    for (int i = 0; i < jobCnt; i++)
    {
        if (jobs[i][1] - 48 == 0) continue; // no prg remaining in job

        for (int j = 3; jobs[i][j] != ';'; j++) // iterate all computers that can run this prg
        {
            if (jobs[i][j] == '_') continue;

            int index = jobs[i][j] - 48;
            if (programs[index] != '_') continue; // computer not free
            
            jobs[i][1]--;
            programs[index] = jobs[i][0];

            if (findAllocation(remaining - 1)) return true;

            jobs[i][1]++;
            programs[index] = '_';
        }
    }

    return false;
}

int programsRemaining()
{
    int remaining = 0;
    for (int i = 0; i < jobCnt; i++)
        remaining += jobs[i][1] - 48;
    return remaining;
}

int getConflictCount(int computer)
{
    int cnt = 0;
    for (int i = 0; i < jobCnt; i++)
        for (int j = 3; jobs[i][j] != ';'; j++)
            if (jobs[i][j] - 48 == computer) cnt++;
    return cnt;
}

void processDefinite()
{
    for (int i = 0; i < jobCnt; i++)
    {
        for (int j = 3; jobs[i][j] != ';'; j++)
        {
            if (jobs[i][1] - 48 == 0) continue; // no prg remaining in job

            int conflicts = getConflictCount(jobs[i][j] - 48);
            if (conflicts == 1)
            {
                programs[jobs[i][j] - 48] = jobs[i][0];
                jobs[i][j] = '_';
                jobs[i][1]--;
            }
        }
    }
}

void processJobs()
{
    for (int i = 0; i < MAX_PROGRAMS; i++)
        programs[i] = '_';

    processDefinite();

    if (findAllocation(programsRemaining()))
    {
        for (int i = 0; i < MAX_PROGRAMS; i++)
            printf("%c", programs[i]);
        putchar('\n');
    }
    else
        printf("!\n");
}

// presentation error
int main()
{
    while (true)
    {
        fgets(jobs[jobCnt], 40, stdin);
        jobCnt++;

        char c = cin.peek();
        if (c == '\n')
        {
            processJobs();
            getchar();
            jobCnt = 0;
        }
        else if (c == EOF)
        {
            processJobs();
            break;
        }
    }
}

/*

A4 01234;
Q1 5;
P4 56789;

A4 01234;
Q1 5;
P5 56789;

AAAA_QPPPP
!

*/
