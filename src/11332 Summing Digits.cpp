#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX_LEN 11

using namespace std;

char arr[MAX_LEN];

void getSum()
{
    int sum = 0;
    for (int i = 0; i < strlen(arr); i++)
        sum += arr[i] - 48;
    sprintf(arr, "%d", sum);
}

int main()
{
    while (true)
    {
        string str;
        getline(cin, str);
        if (str.length() == 1 && str[0] == '0') break;

        strcpy(arr, str.c_str());

        while (strlen(arr) != 1)
            getSum();

        printf("%s\n", arr);
    }

}

/*

2
11
47
1234567892
0

2
2
2
2

*/
