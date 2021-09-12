#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
 /*following is Kosaraju’s DFS based simple algorithm that does two DFS traversals of graph: 
1) Initialize all vertices as not visited.
2) Do a DFS traversal of graph starting from any arbitrary vertex v. If DFS traversal doesn’t visit all vertices, then return false.
3) Reverse all arcs (or find transpose or reverse of graph) 
4) Mark all vertices as not-visited in reversed graph.
5) Do a DFS traversal of reversed graph starting from same vertex v (Same as step 2). If DFS traversal doesn’t visit all vertices, then return false. Otherwise return true.
The idea is, if every node can be reached from a vertex v, and every node can reach v, then the graph is strongly connected. In step 2, we check if all vertices are reachable from v. In step 4, we check if all vertices can reach v (In reversed graph, if all vertices are reachable from v, then all vertices can reach v in original graph). 
Following is the implementation of above algorithm.*/
// https://www.techiedelight.com/check-given-graph-strongly-connected-not/
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
 
    // Constructor
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
 
// Function to perform DFS traversal on the graph on a graph
void DFS(Graph const &graph, int v, vector<bool> &visited)
{
    // mark current node as visited
    visited[v] = true;
 
    // do for every edge `v —> u`
    for (int u: graph.adjList[v])
    {
        // `u` is not visited
        if (!visited[u]) {
            DFS(graph, u, visited);
        }
    }
}
 
// Function to check if the graph is strongly connected or not
bool check(Graph const &graph, int N)
{
    // to keep track of whether a vertex is visited or not
    vector<bool> visited(N);
 
    // choose a random starting point
    int v = 0;
 
    // run a DFS starting at `v`
    DFS(graph, v, visited);
 
    // If DFS traversal doesn't visit all vertices,
    // then the graph is not strongly connected
    if (find(visited.begin(), visited.end(), false) != visited.end()) {
        return false;
    }
 
    // reset visited vector
    fill(visited.begin(), visited.end(), false);
 
    // Reverse the direction of all edges in the
    // directed graph
    vector<Edge> edges;
    for (int i = 0; i < N; i++)
    {
        for (int j: graph.adjList[i]) {
            edges.push_back({j, i});
        }
    }
 
    // Create a graph from reversed edges
    Graph gr(edges, N);
 
    // Again run a DFS starting at `v`
    DFS(gr, v, visited);
 
    // If DFS traversal doesn't visit all vertices,
    // then the graph is not strongly connected
    if (find(visited.begin(), visited.end(), false) != visited.end()) {
        return false;
    }
 
    // if a graph "passes" both DFSs, it is strongly connected
    return true;
}
 
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
 
    // check if the graph is not strongly connected or not
    if (check(graph, N)) {
        cout << "The graph is strongly connected";
    }
    else {
        cout << "The graph is not strongly connected";
    }
 
    return 0;
}


