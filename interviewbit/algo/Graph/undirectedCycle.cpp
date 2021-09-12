//method 1 is by union set elogv
//bfs  if cross edge is there
// dfs if backedge 
 

// Data structure to store a graph edge
// struct Edge {
//     int src, dest;
// }; 
// // A class to represent a graph object
// class Graph
// {
// public:
//     // a vector of vectors to represent an adjacency list
//     vector<vector<int>> adjList;
//     // Graph Constructor
//     Graph(vector<Edge> const &edges, int N)
//     {
//         // resize the vector to hold `N` elements of type `vector<int>`
//         adjList.resize(N);
//         // add edges to the undirected graph
//         for (auto &edge: edges)
//         {
//             adjList[edge.src].push_back(edge.dest);
//             adjList[edge.dest].push_back(edge.src);
//         }
//     }
// };
// // Node to store vertex and its parent info in BFS
// struct Node {
//     int v, parent;
// };
 
// // Perform BFS on the graph starting from vertex `src` and
// // return true if a cycle is found in the graph
// bool BFS(Graph const &graph, int src, int N)
// {
//     // to keep track of whether a vertex is discovered or not
//     vector<bool> discovered(N);
//     // mark the source vertex as discovered
//     discovered[src] = true;
//     // create a queue for doing BFS and
//     // enqueue source vertex
//     queue<Node> q;
//     q.push({src, -1});
 
//     // loop till queue is empty
//     while (!q.empty())
//     {
//         // dequeue front node and print it
//         Node node = q.front();
//         q.pop();
 
//         // do for every edge `v —> u`
//         for (int u: graph.adjList[node.v])
//         {
//             if (!discovered[u])
//             {
//                 // mark it as discovered
//                 discovered[u] = true;
 
//                 // construct the queue node containing info
//                 // about vertex and enqueue it
//                 q.push({ u, node.v });
//             }
 
//             // `u` is discovered, and `u` is not a parent
//             else if (u != node.parent)
//             {
//                 // we found a cross-edge, i.e., the cycle is found
//                 return true;
//             }
//         }
//     }
 
//     // no cross-edges were found in the graph
//     return false;
// }
 
// int main()
// {
//     // initialize edges as per the above diagram
//     vector<Edge> edges =
//     {
//         {1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
//         {5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}, {6, 10}
//         // edge `6 —> 10` introduces a cycle in the graph
//     };
 
//     // total number of nodes in the graph
//     int N = 13;
 
//     // build a graph from the given edges
//     Graph graph(edges, N);
 
//     // Perform BFS traversal in connected components of a graph
//     if (BFS(graph, 1, N)) {
//         cout << "The graph contains a cycle";
//     }
//     else {
//         cout << "The graph doesn't contain any cycle";
//     }
 
//     return 0;
// }


// dfs
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
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
 
        // add edges to the undirected graph
        for (auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
 
// Perform DFS on the graph and returns true if any back-edge
// is found in the graph
bool DFS(Graph const &graph, int v, vector<bool> &discovered,
        int parent)
{
    // mark the current node as discovered
    discovered[v] = true;
 
    // do for every edge `v —> w`
    for (int w: graph.adjList[v])
    {
        // if `w` is not discovered
        if (!discovered[w])
        {
            if (DFS(graph, w, discovered, v)) {
                return true;
            }
        }
 
        // if `w` is discovered, and `w` is not a parent
        else if (w != parent)
        {
            // we found a back-edge (cycle)
            return true;
        }
    }
 
    // No back-edges were found in the graph
    return false;
}
 
int main()
{
    // initialize edges as per the above diagram
    vector<Edge> edges =
    {
        {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
        {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}, {11, 12}
        // edge `11 —> 12` introduces a cycle in the graph
    };
 
    // total number of nodes in the graph
    int N = 13;
 
    // build a graph from the given edges
    Graph graph(edges, N);
 
    // to keep track of whether a vertex is discovered or not
    vector<bool> discovered(N);
 
    // Perform DFS traversal from the first vertex
    if (DFS(graph, 1, discovered, -1)) {
        cout << "The graph contains a cycle";
    }
    else {
        cout << "The graph doesn't contain any cycle";
    }
 
    return 0;
}


