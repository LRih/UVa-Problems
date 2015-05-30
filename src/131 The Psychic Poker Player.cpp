#include <stdio.h>
#include <cstring>

using namespace std;

char hand[5][3];
char deck[5][3];

char newHand[5][3];
int numCount[14];
int suitCount[4];

char best[30];


void setNumCount()
{
    for (int i = 0; i < 14; i++)
        numCount[i] = 0;

    for (int i = 0; i < 5; i++)
    {
        switch (newHand[i][0])
        {
            case 'A': numCount[0]++; numCount[13]++; break;
            case '2': numCount[1]++; break;
            case '3': numCount[2]++; break;
            case '4': numCount[3]++; break;
            case '5': numCount[4]++; break;
            case '6': numCount[5]++; break;
            case '7': numCount[6]++; break;
            case '8': numCount[7]++; break;
            case '9': numCount[8]++; break;
            case 'T': numCount[9]++; break;
            case 'J': numCount[10]++; break;
            case 'Q': numCount[11]++; break;
            case 'K': numCount[12]++; break;
        }
    }
}

void setSuitCount()
{
    for (int i = 0; i < 4; i++)
        suitCount[i] = 0;

    for (int i = 0; i < 5; i++)
    {
        switch (newHand[i][1])
        {
            case 'H': suitCount[0]++; break;
            case 'D': suitCount[1]++; break;
            case 'S': suitCount[2]++; break;
            case 'C': suitCount[3]++; break;
        }
    }
}

void setHand(int d1, int d2, int d3, int d4, int d5)
{
    int deckIndex = 0;

    if (d1 == 1)
    {
        strcpy(newHand[0], deck[deckIndex]);
        deckIndex++;
    }
    else strcpy(newHand[0], hand[0]);

    if (d2 == 1)
    {
        strcpy(newHand[1], deck[deckIndex]);
        deckIndex++;
    }
    else strcpy(newHand[1], hand[1]);

    if (d3 == 1)
    {
        strcpy(newHand[2], deck[deckIndex]);
        deckIndex++;
    }
    else strcpy(newHand[2], hand[2]);

    if (d4 == 1)
    {
        strcpy(newHand[3], deck[deckIndex]);
        deckIndex++;
    }
    else strcpy(newHand[3], hand[3]);

    if (d5 == 1)
    {
        strcpy(newHand[4], deck[deckIndex]);
        deckIndex++;
    }
    else strcpy(newHand[4], hand[4]);

    setNumCount();
    setSuitCount();
}

void setBest(int score)
{
    switch (score)
    {
        case 0: strcpy(best, "highest-card"); break;
        case 1: strcpy(best, "one-pair"); break;
        case 2: strcpy(best, "two-pairs"); break;
        case 3: strcpy(best, "three-of-a-kind"); break;
        case 4: strcpy(best, "straight"); break;
        case 5: strcpy(best, "flush"); break;
        case 6: strcpy(best, "full-house"); break;
        case 7: strcpy(best, "four-of-a-kind"); break;
        case 8: strcpy(best, "straight-flush"); break;
    }
}


bool isPair()
{
    for (int i = 0; i < 13; i++)
        if (numCount[i] == 2) return true;
    return false;
}

bool isTwoPairs()
{
    int count = 0;
    for (int i = 0; i < 13; i++)
        if (numCount[i] == 2) count++;
    return count == 2;
}

bool isThreeOfAKind()
{
    for (int i = 0; i < 13; i++)
        if (numCount[i] == 3) return true;
    return false;
}

bool isStraight()
{
    int count = 0;
    for (int i = 0; i < 14; i++)
    {
        if (numCount[i] == 1) count++;
        else count = 0;
        if (count == 5) return true;
    }
    return false;
}

bool isFlush()
{
    for (int i = 0; i < 4; i++)
        if (suitCount[i] == 5) return true;
    return false;
}

bool isFullHouse()
{
    return isThreeOfAKind() && isPair();
}

bool isFourOfAKind()
{
    for (int i = 0; i < 13; i++)
        if (numCount[i] == 4) return true;
    return false;
}

bool isStraightFlush()
{
    return isFlush() && isStraight();
}

int getScore(int d1, int d2, int d3, int d4, int d5)
{
    setHand(d1, d2, d3, d4, d5);
    if (isStraightFlush()) return 8;
    else if (isFourOfAKind()) return 7;
    else if (isFullHouse()) return 6;
    else if (isFlush()) return 5;
    else if (isStraight()) return 4;
    else if (isThreeOfAKind()) return 3;
    else if (isTwoPairs()) return 2;
    else if (isPair()) return 1;
    else return 0;
}


int main()
{
    while (scanf("%s %s %s %s %s %s %s %s %s %s", hand[0], hand[1], hand[2], hand[3], hand[4], deck[0], deck[1], deck[2], deck[3], deck[4]) == 10)
    {
        int score = 0;
        int newScore = getScore(0, 0, 0, 0, 0); if (newScore > score) score = newScore;

        newScore = getScore(1, 0, 0, 0, 0); if (newScore > score) score = newScore;
        newScore = getScore(0, 1, 0, 0, 0); if (newScore > score) score = newScore;
        newScore = getScore(0, 0, 1, 0, 0); if (newScore > score) score = newScore;
        newScore = getScore(0, 0, 0, 1, 0); if (newScore > score) score = newScore;
        newScore = getScore(0, 0, 0, 0, 1); if (newScore > score) score = newScore;

        newScore = getScore(1, 1, 0, 0, 0); if (newScore > score) score = newScore;
        newScore = getScore(1, 0, 1, 0, 0); if (newScore > score) score = newScore;
        newScore = getScore(1, 0, 0, 1, 0); if (newScore > score) score = newScore;
        newScore = getScore(1, 0, 0, 0, 1); if (newScore > score) score = newScore;
        newScore = getScore(0, 1, 1, 0, 0); if (newScore > score) score = newScore;
        newScore = getScore(0, 1, 0, 1, 0); if (newScore > score) score = newScore;
        newScore = getScore(0, 1, 0, 0, 1); if (newScore > score) score = newScore;
        newScore = getScore(0, 0, 1, 1, 0); if (newScore > score) score = newScore;
        newScore = getScore(0, 0, 1, 0, 1); if (newScore > score) score = newScore;
        newScore = getScore(0, 0, 0, 1, 1); if (newScore > score) score = newScore;

        newScore = getScore(1, 1, 1, 0, 0); if (newScore > score) score = newScore;
        newScore = getScore(1, 1, 0, 1, 0); if (newScore > score) score = newScore;
        newScore = getScore(1, 1, 0, 0, 1); if (newScore > score) score = newScore;
        newScore = getScore(1, 0, 1, 1, 0); if (newScore > score) score = newScore;
        newScore = getScore(1, 0, 1, 0, 1); if (newScore > score) score = newScore;
        newScore = getScore(1, 0, 0, 1, 1); if (newScore > score) score = newScore;
        newScore = getScore(0, 1, 1, 1, 0); if (newScore > score) score = newScore;
        newScore = getScore(0, 1, 1, 0, 1); if (newScore > score) score = newScore;
        newScore = getScore(0, 1, 0, 1, 1); if (newScore > score) score = newScore;
        newScore = getScore(0, 0, 1, 1, 1); if (newScore > score) score = newScore;

        newScore = getScore(1, 1, 1, 1, 0); if (newScore > score) score = newScore;
        newScore = getScore(1, 1, 1, 0, 1); if (newScore > score) score = newScore;
        newScore = getScore(1, 1, 0, 1, 1); if (newScore > score) score = newScore;
        newScore = getScore(1, 0, 1, 1, 1); if (newScore > score) score = newScore;
        newScore = getScore(0, 1, 1, 1, 1); if (newScore > score) score = newScore;

        newScore = getScore(1, 1, 1, 1, 1); if (newScore > score) score = newScore;

        setBest(score);
        printf("Hand: %s %s %s %s %s Deck: %s %s %s %s %s Best hand: %s\n", hand[0], hand[1], hand[2], hand[3], hand[4], deck[0], deck[1], deck[2], deck[3], deck[4], best);
    }
}

/*

TH JH QC QD QS QH KH AH 2S 6S
2H 2S 3H 3S 3C 2D 3D 6C 9C TH
2H 2S 3H 3S 3C 2D 9C 3D 6C TH
2H AD 5H AC 7H AH 6H 9H 4H 3C
AC 2D 9C 3S KD 5S 4D KS AS 4C
KS AH 2H 3C 4H KC 2C TC 2D AS
AH 2C 9S AD 3C QH KS JS JD KD
6C 9C 8C 2D 7C 2H TC 4C 9S AH
3D 5S 2H QD TD 6S KH 9H AD QH

Hand: TH JH QC QD QS Deck: QH KH AH 2S 6S Best hand: straight-flush
Hand: 2H 2S 3H 3S 3C Deck: 2D 3D 6C 9C TH Best hand: four-of-a-kind
Hand: 2H 2S 3H 3S 3C Deck: 2D 9C 3D 6C TH Best hand: full-house
Hand: 2H AD 5H AC 7H Deck: AH 6H 9H 4H 3C Best hand: flush
Hand: AC 2D 9C 3S KD Deck: 5S 4D KS AS 4C Best hand: straight
Hand: KS AH 2H 3C 4H Deck: KC 2C TC 2D AS Best hand: three-of-a-kind
Hand: AH 2C 9S AD 3C Deck: QH KS JS JD KD Best hand: two-pairs
Hand: 6C 9C 8C 2D 7C Deck: 2H TC 4C 9S AH Best hand: one-pair
Hand: 3D 5S 2H QD TD Deck: 6S KH 9H AD QH Best hand: highest-card

*/
