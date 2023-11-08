#include <bits/stdc++.h>

using namespace std;

#define N 6

void print_Sol(int*);
int min_Distance(int*, bool*);

void dijkstra(int graph[N][N], int src)
{
    int dist[N];
    bool spt[N];

    for(auto i=0; i<N; i++)
        dist[i] = INT_MAX, spt[i] = false;

    dist[src] = 0;

    for(auto count=0; count<N-1; count++)
    {
        int m = min_Distance(dist, spt);

        spt[m] = true;

        for(auto v=0; v<N; v++)
            if(!spt[v] && graph[m][v] && dist[m] != INT_MAX && dist[m] + graph[m][v] < dist[v])
                dist[v] = dist[m] + graph[m][v];

    }

    print_Sol(dist);
}

void print_Sol(int dist[])
{
    cout << "Vertex Distance from Source: " << '\n';
    
    for(auto i=0; i<N; i++)
        cout << i << " " << dist[i] << '\n';
}

int min_Distance(int dist[], bool spt[])
{
    int min = INT_MAX, index;

    for(auto v=0; v<N; v++)
        if(spt[v] == false && dist[v] <= min)
            min = dist[v], index = v;

    return index;
}

int32_t main()
{
    int graph[N][N] = { 
        {0, 2, 1, 0, 0, 0},
        {2, 0, 7, 0, 8, 4},
        {1, 7, 0, 7, 0, 3},
        {0, 0, 7, 0, 8, 4},
        {0, 8, 0, 8, 0, 5},
        {0, 4, 3, 4, 5, 0}
    };

    dijkstra(graph, 0);

    return 0;
}