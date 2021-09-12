#include <iostream>
#include <vector>
using namespace std;



 // If the departure time of vertex `v` is greater than equal
            // to the departure time of `u`, they form a back edge.
 
            // Note that departure[u] will be equal to
            // departure[v] only if `u = v`, i.e., vertex
            // contain an edge to itself
             // check if the given directed graph is DAG or not


             
// Data structure to store a graph edge
struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
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
 
// Perform DFS on the graph and set the departure time of all
// vertices of the graph
int DFS(Graph const &graph, int v, vector<bool>
    &discovered, vector<int> &departure, int &time)
{
    // mark the current node as discovered
    discovered[v] = true;
 
    // do for every edge `v —> u`
    for (int u: graph.adjList[v])
    {
        // if `u` is not yet discovered
        if (!discovered[u]) {
            DFS(graph, u, discovered, departure, time);
        }
    }
 
    // ready to backtrack
    // set departure time of vertex `v`
    departure[v] = time++;
}
 
// Returns true if given directed graph is DAG
bool isDAG(Graph const &graph, int N)
{
    // keep track of whether a vertex is discovered or not
    vector<bool> discovered(N);
 
    // keep track of the departure time of a vertex in DFS
    vector<int> departure(N);
 
    int time = 0;
 
    // Perform DFS traversal from all undiscovered vertices
    // to visit all connected components of a graph
    for (int i = 0; i < N; i++)
    {
        if (discovered[i] == false) {
            DFS(graph, i, discovered, departure, time);
        }
    }
 
    // check if the given directed graph is DAG or not
    for (int u = 0; u < N; u++)
    {
        // check if `(u, v)` forms a back-edge.
        for (int v: graph.adjList[u])
        {
            // If the departure time of vertex `v` is greater than equal
            // to the departure time of `u`, they form a back edge.
 
            // Note that departure[u] will be equal to
            // departure[v] only if `u = v`, i.e., vertex
            // contain an edge to itself
            if (departure[u] <= departure[v]) {
                return false;
            }
        }
    }
 
    // no back edges
    return true;
}
 
int main()
{
    // vector of graph edges as per the above diagram
    vector<Edge> edges =
    {
        {0, 1}, {0, 3}, {1, 2}, {1, 3}, {3, 2}, {3, 4},
        {3, 0}, {5, 6}, {6, 3}
    };
 
    // total number of nodes in the graph
    int N = 7;
 
    // build a graph from the given edges
    Graph graph(edges, N);
 
    // check if the given directed graph is DAG or not
    if (isDAG(graph, N)) {
        cout << "The graph is a DAG";
    }
    else {
        cout << "The graph is not a DAG";
    }
 
    return 0;
}