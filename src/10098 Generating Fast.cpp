#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string str;

    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        sort(str.begin(), str.end());
        do
        {
            cout << str << endl;
        } while (next_permutation(str.begin(), str.end()));
        printf("\n");
    }
}

/*

3
ab
abc
bca

ab
ba

abc
acb
bac
bca
cab
cba

abc
acb
bac
bca
cab
cba

*/
