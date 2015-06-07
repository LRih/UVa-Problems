#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

bool isBalance(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[')
            s.push(str[i]);
        else if (str[i] == ')' && s.size() > 0 && s.top() == '(')
            s.pop();
        else if (str[i] == ']' && s.size() > 0 && s.top() == '[')
            s.pop();
        else
            return false;
    }
    return s.size() == 0;
}

int main()
{
    string str;

    int n;
    scanf("%d\n", &n);
    while (n--)
    {
        getline(cin, str);
        if (isBalance(str)) printf("Yes\n");
        else printf("No\n");
    }
}

/*

3
([])
(([()])))
([()[]()])()

Yes
No
Yes

*/
