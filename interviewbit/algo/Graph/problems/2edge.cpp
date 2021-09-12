// A graph is said to be 2-edge connected if, on removing any edge of the graph, it still remains connected, i.e. it contains no Bridges. 
// An edge in an undirected connected graph is a bridge iff removing it disconnects the graph

// 
// We can say that the graph is 2 edge connected if and only if for every edge
// in the graph, u->v there is at least one back-edge that is going out of a subtree rooted at
//  v to some ancestor of u. when we say subtree rooted at v we mean all of v's descendants, including the vertex itsefl.
// in other words when we backtrack from vertex v, we need to ensure that there is some backedge from some descendant of 
// v to some proper ancestor of v


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
 
        // add edges to the undirected graph
        for (auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
 
// Perform DFS on the graph starting from vertex `v` and find
// all bridges in the process
int DFS(Graph const &graph, int v, vector<bool> discovered,
                int arrival[], int parent, int &time)
{
    // set the arrival time of vertex `v`
    arrival[v] = ++time;
 
    // mark vertex as discovered
    discovered[v] = true;
 
    // initialize `t` with the arrival time of vertex `v`
    int t = arrival[v];
 
    // `(v, w)` forms an edge
    for (int w: graph.adjList[v])
    {
        // if `w` is not discovered
        if (!discovered[w]) {
            t = min(t, DFS(graph, w, discovered, arrival, v, time));
        }
        // if `w` is discovered, and `w` is not a parent of `v`
        else if (w != parent)
        {
            // If vertex `w` is already discovered, there is a back edge starting
            // from `v`. Note that as `discovered[u]` is already
            // true, `arrival[u]` is already defined
            t = min(t, arrival[w]);
        }
    }
 
    // if the value of `t` remains unchanged, i.e., it is equal
    // to the arrival time of vertex `v`, and if `v` is not the root node,
    // then `(parent[v] —> v)` forms a bridge
    if (t == arrival[v] && parent != -1) {
        cout << parent << ", " << v << endl;
    }
 
    // return the minimum arrival time
    return t;
}
 
// 2–edge connectivity in a graph
int main()
{
    // vector of graph edges as per the above diagram
    vector<Edge> edges = {
        {0, 2}, {1, 2}, {2, 3}, {2, 4}, {3, 4}, {3, 5}
    };
 
    // total number of nodes in the graph
    int N = 10;
 
    // build a graph from the given edges
    Graph graph(edges, N);
 
    // to keep track of whether a vertex is discovered or not
    vector<bool> discovered(N);
 
    // stores arrival time of a node in DFS
    int arrival[N];
 
    int start = 0, parent = -1, time = 0;
 
    // As the given graph is connected, DFS will cover every node
    DFS(graph, start, discovered, arrival, parent, time);
 
    return 0;
}