#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    Graph(int vertices);

    void add_edge(int src, int dst);

    int count_paths(int src, int dst, int vertices);

private:
    int g_vertices;
    
    list<int>* g_neighbours;

    void path_counter(int src, int dst, int& path_count, vector<bool>& visited);
};