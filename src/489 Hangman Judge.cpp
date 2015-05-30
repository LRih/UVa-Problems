#include <stdio.h>
#include <iostream>

using namespace std;

string word, guesses;

bool guess(char c)
{
    bool correct = false;
    for (int i = 0; i < word.length(); i++)
    {
        if (word.at(i) == c)
        {
            word[i] = '*';
            correct = true;
        }
    }
    return correct;
}

bool isWin()
{
    for (int i = 0; i < word.length(); i++)
        if (word.at(i) != '*') return false;
    return true;
}

int main()
{
    int round;
    while (true)
    {
        scanf("%d", &round);
        if (round == -1) break;

        int tries = 0;

        getchar();

        getline(cin, word);
        getline(cin, guesses);

        printf("Round %d\n", round);

        for (int i = 0; i < guesses.length(); i++)
        {
            if (guess(guesses[i]))
            {
                if (isWin())
                {
                    printf("You win.\n");
                    break;
                }
            }
            else
            {
                tries++;
                if (tries == 7)
                {
                    printf("You lose.\n");
                    break;
                }
            }

            if (i == guesses.length() - 1) printf("You chickened out.\n");
        }
    }
}

/*

1
cheese
chese
2
cheese
abcdefg
3
cheese
abcdefgij
-1

Round 1
You win.
Round 2
You chickened out.
Round 3
You lose.

*/
