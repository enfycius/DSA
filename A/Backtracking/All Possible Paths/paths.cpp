#include <bits/stdc++.h>
#include "./../graph.cpp"

using namespace std;

int main(void)
{
    Graph g(5);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 4);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 3);
    g.add_edge(2, 1);
    g.add_edge(3, 2);

    cout << g.count_paths(0, 4, 5) << endl;

    return 0;
}