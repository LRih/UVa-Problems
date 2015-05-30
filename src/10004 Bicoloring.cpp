#include <stdio.h>

using namespace std;

int n;
int matrix[200][200];
int painted[200];

bool paint(int node, int color)
{
    painted[node] = color;

    // check adjacent same color
    for (int i = 0; i < n; i++)
    {
        if (matrix[node][i] == 1 && painted[i] == color)
            return false;
    }

    // for each unpainted node, try each color
    for (int i = 0; i < n; i++)
        if (matrix[node][i] == 1 && painted[i] == 0)
            if (!paint(i, color == 1 ? 2 : 1)) return false;

    return true;
}

int main()
{
    while (true)
    {
        scanf("%d", &n);
        if (n == 0) break;

        int edges;
        scanf("%d", &edges);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matrix[i][j] = 0;
        for (int i = 0; i < n; i++)
            painted[i] = 0;

        for (int i = 0; i < edges; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            matrix[x][y] = matrix[y][x] = 1;
        }

        if (paint(0, 1)) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
}

/*

3
3
0 1
1 2
2 0
3
2
0 1
1 2
9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0

NOT BICOLORABLE.
BICOLORABLE.
BICOLORABLE.

*/
