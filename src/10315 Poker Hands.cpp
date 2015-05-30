#include <stdio.h>
#include <iostream>

using namespace std;

string hands;

bool isFlush;
int numbers[14];

void calcFlush(int index)
{
    char suit = hands.at(index + 1);
    for (int i = 1; i < 5; i++)
    {
        if (hands.at(index + 1 + 3 * i) != suit)
        {
            isFlush = false;
            return;
        }
    }
    isFlush = true;
}

void calcNumbers(int index)
{
    for (int i = 0; i < 14; i++)
        numbers[i] = 0;
    for (int i = 0; i < 5; i++)
    {
        switch (hands.at(index + 3 * i))
        {
            case 'A': numbers[0]++; numbers[13]++; break;
            case '2': numbers[1]++; break;
            case '3': numbers[2]++; break;
            case '4': numbers[3]++; break;
            case '5': numbers[4]++; break;
            case '6': numbers[5]++; break;
            case '7': numbers[6]++; break;
            case '8': numbers[7]++; break;
            case '9': numbers[8]++; break;
            case 'T': numbers[9]++; break;
            case 'J': numbers[10]++; break;
            case 'Q': numbers[11]++; break;
            case 'K': numbers[12]++; break;
        }
    }
}


int getHighestNum()
{
    for (int i = 13; i > 0; i--)
        if (numbers[i] > 0) return i;
}

int getHighCard()
{
    // maybe doesn't work for numbers >= 10
    int mag = 10000;
    int sum = 1;
    for (int i = 13; i > 0; i--)
    {
        if (numbers[i] == 1)
        {
            sum += i * mag;
            mag /= 10;
        }
    }
    return sum;
}

int getPair()
{
    for (int i = 1; i < 14; i++)
        if (numbers[i] == 2) return i;
    return 0;
}

int getTwoPairs()
{
    int count = 0;
    for (int i = 1; i < 14; i++)
    {
        if (numbers[i] == 2) count++;
        if (count == 2) return i;
    }
    return 0;
}

int getThreeOfAKind()
{
    for (int i = 1; i < 14; i++)
        if (numbers[i] == 3) return i;
    return 0;
}

int getStraight()
{
    int count = 0;
    for (int i = 0; i < 14; i++)
    {
        if (numbers[i] == 1) count++;
        else count = 0;
        if (count == 5) return getHighestNum();
    }
    return 0;
}

int getFullHouse()
{
    int three = getThreeOfAKind();
    int pair = getPair();

    if (three > 0 && pair > 0) return three;
    return 0;
}

int getFourOfAKind()
{
    for (int i = 0; i < 13; i++)
        if (numbers[i] == 4) return getHighestNum();
    return 0;
}

int getStraightFlush()
{
    int straight = getStraight();
    if (straight > 0 && isFlush) return straight;
    else return 0;
}


int getScore(int index)
{
    int score;

    calcFlush(index);
    calcNumbers(index);

    score = getStraightFlush();
    if (score > 0) return score + 9000000;
    score = getFourOfAKind();
    if (score > 0) return score + 8000000;
    score = getFullHouse();
    if (score > 0) return score + 7000000;
    if (isFlush) return 6000000 + getHighCard();
    score = getStraight();
    if (score > 0) return score + 5000000;
    score = getThreeOfAKind();
    if (score > 0) return score + 4000000;
    score = getTwoPairs();
    if (score > 0) return score + 3000000 + getHighCard();
    score = getPair();
    if (score > 0) return score + 2000000 + getHighCard();
    return getHighCard() + 1000000;
}

// unfinished
int main()
{
    while (getline(cin, hands))
    {
        int score1 = getScore(0);
        int score2 = getScore(15);

        printf("\n%d - %d", score1, score2);

        if (score1 > score2) printf("Black wins.\n");
        else if (score1 < score2) printf("White wins.\n");
        else printf("Tie.\n");
    }
}

/*

2H 3D 5S 9C KD 2C 3H 4S 8C AH
2H 4S 4C 2D 4H 2S 8S AS QS 3S
2H 3D 5S 9C KD 2C 3H 4S 8C KH
2H 3D 5S 9C KD 2D 3H 5C 9S KH

White wins.
Black wins.
Black wins.
Tie.

*/
