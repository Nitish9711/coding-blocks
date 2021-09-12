
/* 
strongly connected it is one travesal follow 2 traversal of kosarjau's algo
for all edges u->v there is at least one back edge or cross edge that is going out of the subtree rooted at v.

*/
#include <iostream>
#include <vector>

using namespace std;
 
// Data structure to store a graph edge
struct Edge {
    int src, dest;
};
 
class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to hold `N` elements of type `vector<int>`
        adjList.resize(N);
 
        // add edges to the directed graph
        for (auto &edge: edges) {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};
 
// Perform DFS on the graph starting from vertex `v`
int DFS(Graph const &graph, int v, vector<bool>
    &discovered, int arrival[], bool &isSC, int &time)
{
    // terminate the search if the graph is not strongly
    // connected
    if (!isSC) {
        return false;
    }
 
    // set the arrival time of vertex `v`
    arrival[v] = ++time;
 
    // mark vertex as discovered
    discovered[v] = true;
 
    // initialize `arr` to the arrival time of vertex `v`
    int arr = arrival[v];
 
    // do for every edge `v —> w`
    for (int w: graph.adjList[v])
    {
        // vertex `w` is not yet explored
        if (!discovered[w])
        {
            arr = min(arr, DFS(graph, w, discovered,
                    arrival, isSC, time));
        }
        // vertex `w` is explored before
        else {
            // If the vertex is `w` is already discovered,
            // there must be either a cross edge
            // or a back edge starting from `v`. Note that
            // the arrival time is already defined for `w`
            arr = min(arr, arrival[w]);
        }
    }
 
    // if `v` is not a root node and the value of the arr didn't
    // change, i.e., it is still set to the arrival time of
    // vertex `v`, the graph is not strongly connected
    if (v != 0 && arr == arrival[v]) {
        isSC = false;
    }
 
    // we return the minimum arrival time
    return arr;
}
 
// Check if the given graph is strongly connected or not
int main()
{
    // vector of graph edges as per the above diagram
    vector<Edge> edges = {
        {0, 4}, {1, 0}, {1, 2}, {2, 1}, {2, 4},
        {3, 1}, {3, 2}, {4, 3}
    };
 
    // total number of nodes in the graph
    int N = 5;
 
    // build a graph from the given edges
    Graph graph(edges, N);
 
    // to keep track of whether a vertex is discovered or not
    vector<bool> discovered(N);
 
    // array to store the arrival time of vertex
    int arrival[N];
 
    // flag to determine if a graph is strongly connected
    // or not
    bool isSC = true;
    int time = -1;
 
    // Perform DFS traversal starting from the first vertex.
    DFS(graph, 0, discovered, arrival, isSC, time);
 
    // If DFS traversal doesn't visit all vertices,
    // then the graph is not strongly connected
    for (int i = 0; i < N; i++)
    {
        if (discovered[i] == false) {
            isSC = false;
        }
    }
 
    if (isSC) {
        cout << "The graph is strongly connected";
    }
    else {
        cout << "The graph is not strongly connected";
    }
 
    return 0;
}