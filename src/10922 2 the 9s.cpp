#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX_LEN 1001

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

        int degree = 0;
        do
        {
            getSum();
            degree++;
        } while (strlen(arr) != 1);

        cout << str;
        if (arr[0] == '9') printf(" is a multiple of 9 and has 9-degree %d.\n", degree);
        else printf(" is not a multiple of 9.\n");
    }

}

/*

999999999999999999999
9
9999999999999999999999999999998
0

999999999999999999999 is a multiple of 9 and has 9-degree 3.
9 is a multiple of 9 and has 9-degree 1.
9999999999999999999999999999998 is not a multiple of 9.

*/