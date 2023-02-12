#include <bits/stdc++.h>

#define N 5
#define M 5

using namespace std;

int min(int x, int y, int z)
{
    if(x>=y)
        return (y<z) ? y : z;
    else
        return (x<z) ? x : z;
}

int min_cost(int (*cost)[M], int n, int m)
{
    int temp[N][M];
    int i, j;

    temp[0][0] = cost[0][0];

    for(i=1; i<=n; i++)
        temp[i][0] = temp[i-1][0] + cost[i][0];

    for(j=1; j<=m; j++)
        temp[0][j] = temp[0][j-1] + cost[0][j];

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            temp[i][j] = min(temp[i-1][j-1], temp[i-1][j], temp[i][j-1]) \
            + cost[i][j];

    return temp[n][m];
}

int main(void)
{
    int cost[N][M] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25},
    };

    cout << min_cost(cost, 2, 2) << endl;

    return 0;
}