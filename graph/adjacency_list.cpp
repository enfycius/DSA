#include <iostream>

using namespace std;

struct adjNode
{
    int val, cost;
    adjNode* next;
};

struct graphEdge 
{
    int start_ver, end_ver, weight;
};

class DiaGraph
{
    adjNode* getAdjListNode(int value, int weight, adjNode* head)
    {
        adjNode* newNode = new adjNode;
        newNode->val = value;
        newNode->cost = weight;

        newNode->next = head;

        return newNode;
    }

    int N;

public:
    adjNode **head;

    DiaGraph(graphEdge edges[], int n, int N)
    {
        head = new adjNode*[N]();

        this->N = N;

        for(int i=0; i<N; ++i)
            head[i] = nullptr;

        for(unsigned i=0; i<n; i++)
        {
            int start_ver = edges[i].start_ver;
            int end_ver = edges[i].end_ver;
            int weight = edges[i].weight;

            adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);

            head[start_ver] = newNode;
        }
    }

    ~DiaGraph()
    {
        for(int i=0; i<N; i++)
            delete[] head[i];

        delete[] head;
    }
};

void display_AdjList(adjNode* ptr, int i)
{
    while (ptr != nullptr)
    {
        cout << "(" << i << ", " << ptr->val << ", " << ptr->cost << ") ";
        ptr = ptr->next;
    }

    cout << endl;
}

int main()
{
    graphEdge edges[] = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 4, 3},
        {2, 3, 2},
        {3, 1, 4},
        {4, 3, 3}
    };

    int N = 6;
    int n = sizeof(edges) / sizeof(edges[0]);

    DiaGraph diagraph(edges, n, N);

    cout << "Graph adjacency list " << endl << "(start_vertex, end_vertex, weight):" << endl;

    for(int i=0; i<N; i++)
    {
        display_AdjList(diagraph.head[i], i);
    }

    return 0;
}