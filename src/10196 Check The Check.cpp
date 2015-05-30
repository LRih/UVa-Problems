#include <stdio.h>

using namespace std;

char board[8][8];

bool isBoardEmpty()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (board[i][j] != '.') return false;
    return true;
}

int checkPawn(int sx, int sy, bool isWhite)
{
    if (isWhite && sx - 1 != -1)
    {
        if (sy - 1 != -1 && board[sx - 1][sy - 1] == 'k') return 1;
        else if (sy + 1 != 8 && board[sx - 1][sy + 1] == 'k') return 1;
    }

    if (!isWhite && sx + 1 != 8)
    {
        if (sy - 1 != -1 && board[sx + 1][sy - 1] == 'K') return 2;
        else if (sy + 1 != 8 && board[sx + 1][sy + 1] == 'K') return 2;
    }

    return 0;
}

int checkBishop(int sx, int sy, bool isWhite)
{
    // upper left
    int x = sx, y = sy;
    while (true)
    {
        x--; y--;
        if (x == -1 || y == -1) break;
        else if (isWhite && board[x][y] == 'k') return 1;
        else if (!isWhite && board[x][y] == 'K') return 2;
        else if (board[x][y] != '.') break;
    }

    // upper right
    x = sx; y = sy;
    while (true)
    {
        x++; y--;
        if (x == 8 || y == -1) break;
        else if (isWhite && board[x][y] == 'k') return 1;
        else if (!isWhite && board[x][y] == 'K') return 2;
        else if (board[x][y] != '.') break;
    }

    // lower left
    x = sx; y = sy;
    while (true)
    {
        x--; y++;
        if (x == -1 || y == 8) break;
        else if (isWhite && board[x][y] == 'k') return 1;
        else if (!isWhite && board[x][y] == 'K') return 2;
        else if (board[x][y] != '.') break;
    }

    // lower right
    x = sx; y = sy;
    while (true)
    {
        x++; y++;
        if (x == 8 || y == 8) break;
        else if (isWhite && board[x][y] == 'k') return 1;
        else if (!isWhite && board[x][y] == 'K') return 2;
        else if (board[x][y] != '.') break;
    }

    return 0;
}

int checkRook(int sx, int sy, bool isWhite)
{
    // left
    int x = sx, y = sy;
    while (true)
    {
        x--;
        if (x == -1) break;
        else if (isWhite && board[x][y] == 'k') return 1;
        else if (!isWhite && board[x][y] == 'K') return 2;
        else if (board[x][y] != '.') break;
    }

    // right
    x = sx; y = sy;
    while (true)
    {
        x++;
        if (x == 8) break;
        else if (isWhite && board[x][y] == 'k') return 1;
        else if (!isWhite && board[x][y] == 'K') return 2;
        else if (board[x][y] != '.') break;
    }

    // up
    x = sx; y = sy;
    while (true)
    {
        y--;
        if (y == -1) break;
        else if (isWhite && board[x][y] == 'k') return 1;
        else if (!isWhite && board[x][y] == 'K') return 2;
        else if (board[x][y] != '.') break;
    }

    // down
    x = sx; y = sy;
    while (true)
    {
        y++;
        if (y == 8) break;
        else if (isWhite && board[x][y] == 'k') return 1;
        else if (!isWhite && board[x][y] == 'K') return 2;
        else if (board[x][y] != '.') break;
    }

    return 0;
}

int checkKnight(int sx, int sy, bool isWhite)
{
    int x = sx - 2, y = sy - 1;
    if (x >= 0 && y >= 0)
    {
        if (isWhite && board[x][y] == 'k') return 1;
        else if (!isWhite && board[x][y] == 'K') return 2;
    }

    x = sx - 1; y = sy - 2;
    if (x >= 0 && y >= 0)
    {
        if (isWhite && board[x][y] == 'k') return 1;
        else if (!isWhite && board[x][y] == 'K') return 2;
    }
    
    x = sx + 1; y = sy - 2;
    if (x >= 0 && y >= 0)
    {
        if (isWhite && board[x][y] == 'k') return 1;
        else if (!isWhite && board[x][y] == 'K') return 2;
    }
    
    x = sx + 2; y = sy - 1;
    if (x >= 0 && y >= 0)
    {
        if (isWhite && board[x][y] == 'k') return 1;
        else if (!isWhite && board[x][y] == 'K') return 2;
    }
    
    x = sx + 2; y = sy + 1;
    if (x >= 0 && y >= 0)
    {
        if (isWhite && board[x][y] == 'k') return 1;
        else if (!isWhite && board[x][y] == 'K') return 2;
    }
    
    x = sx + 1; y = sy + 2;
    if (x >= 0 && y >= 0)
    {
        if (isWhite && board[x][y] == 'k') return 1;
        else if (!isWhite && board[x][y] == 'K') return 2;
    }
    
    x = sx - 1; y = sy + 2;
    if (x >= 0 && y >= 0)
    {
        if (isWhite && board[x][y] == 'k') return 1;
        else if (!isWhite && board[x][y] == 'K') return 2;
    }
    
    x = sx - 2; y = sy + 1;
    if (x >= 0 && y >= 0)
    {
        if (isWhite && board[x][y] == 'k') return 1;
        else if (!isWhite && board[x][y] == 'K') return 2;
    }

    return 0;
}

int checkQueen(int sx, int sy, bool isWhite)
{
    int bish = checkBishop(sx, sy, isWhite);
    int rook = checkRook(sx, sy, isWhite);

    if (bish > 0) return bish;
    if (rook > 0) return rook;
    return 0;
}

int checkCheck()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int check = 0;
            switch (board[i][j])
            {
                case 'P': check = checkPawn(i, j, true); break;
                case 'p': check = checkPawn(i, j, false); break;
                case 'B': check = checkBishop(i, j, true); break;
                case 'b': check = checkBishop(i, j, false); break;
                case 'R': check = checkRook(i, j, true); break;
                case 'r': check = checkRook(i, j, false); break;
                case 'N': check = checkKnight(i, j, true); break;
                case 'n': check = checkKnight(i, j, false); break;
                case 'Q': check = checkQueen(i, j, true); break;
                case 'q': check = checkQueen(i, j, false); break;
            }
            if (check != 0) return check;
        }
    }
    return 0;
}

int main()
{
    int game = 0;
    while (true)
    {
        game++;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
                scanf("%c", &board[i][j]);
            getchar();
        }
        if (isBoardEmpty()) break;
        getchar();

        switch (checkCheck())
        {
            case 0: printf("Game #%d: no king is in check.\n", game); break;
            case 1: printf("Game #%d: black king is in check.\n", game); break;
            case 2: printf("Game #%d: white king is in check.\n", game); break;
        }
    }
}

/*

..k.....
ppp.pppp
........
.R...B..
........
........
PPPPPPPP
K.......

rnbqkbnr
pppppppp
........
........
........
........
PPPPPPPP
RNBQKBNR

rnbqk.nr
ppp..ppp
....p...
...p....
.bPP....
.....N..
PP..PPPP
RNBQKB.R

........
........
........
........
........
........
........
........

*/
