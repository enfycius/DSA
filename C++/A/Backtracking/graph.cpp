#include "graph.hpp"

using namespace std;

Graph::Graph(int vertices)
{
    g_vertices = vertices;

    g_neighbours = new list<int>[vertices];
}

void Graph::add_edge(int src, int dst)
{
    g_neighbours[src].push_back(dst);
}

int Graph::count_paths(int src, int dst, int vertices)
{
    int path_count = 0;

    vector<bool> visited(vertices, false);
    
    path_counter(src, dst, path_count, visited);

    return path_count;
}

void Graph::path_counter(int src, int dst, int& path_count, vector<bool>& visited)
{
    visited[src] = true;

    if(src == dst)
    {
        path_count++;
    }
    else
    {
        for(auto neighbour : g_neighbours[src])
        {
            if(!visited[neighbour])
            {
                path_counter(neighbour, dst, path_count, visited);
            }
        }
    }
    visited[src] = false;
}