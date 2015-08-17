#include <cstdio>
#include <iostream>

using namespace std;

string num;

bool isDiv11()
{
    int sum = 0;
    for (int i = 0; i < num.length(); i++)
    {
        if (i % 2 == 0) sum += num[i] - 48;
        else sum -= num[i] - 48;
    }
    return sum % 11 == 0;
}

int main()
{
    while (true)
    {
        getline(cin, num);
        if (num.length() == 1 && num[0] == '0')
            break;

        if (isDiv11())
            cout << num << " is a multiple of 11." << endl;
        else
            cout << num << " is not a multiple of 11." << endl;
    }
}

/*

112233
30800
2937
323455693
5038297
112234
0

112233 is a multiple of 11.
30800 is a multiple of 11.
2937 is a multiple of 11.
323455693 is a multiple of 11.
5038297 is a multiple of 11.
112234 is not a multiple of 11.

*/