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
    if(n<0 || m<0)
        return INT_MAX;
    else if(n==0 && m==0)
        return cost[n][m];
    else
        return cost[n][m] + min(min_cost(cost, n-1, m-1), \
        min_cost(cost, n-1, m), min_cost(cost, n, m-1));
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