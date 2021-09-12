// A C++ program to Clone an Undirected Graph
/*The idea is to do a BFS traversal of the graph and while visiting a node make a clone node of it (a copy of original node). 
If a node is encountered which is already visited then it already has a clone node.

How to keep track of the visited/cloned nodes?
A HashMap/Map is required in order to maintain all the nodes which have already been created.
Key stores: Reference/Address of original Node
Value stores: Reference/Address of cloned Node
While visiting the neighboring vertices of a node u get the corresponding cloned node for u , let’s call that cloneNodeU , 
now visit all the neighboring nodes for u and for each neighbor find the corresponding clone node(if not found create one) 
and then push into the neighboring vector of cloneNodeU node.*/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	//A neighbour vector which contains addresses to
	//all the neighbours of a Node
	vector<Node*> neighbours;
};

// A function which clones a Graph and
// returns the address to the cloned
// src node
Node *cloneGraph(Node *src)
{
	//A Map to keep track of all the
	//nodes which have already been created
	map<Node*, Node*> m;
	queue<Node*> q;

	// Enqueue src node
	q.push(src);
	Node *node;

	// Make a clone Node
	node = new Node();
	node->val = src->val;

	// Put the clone node into the Map
	m[src] = node;
	while (!q.empty())
	{
		//Get the front node from the queue
		//and then visit all its neighbours
		Node *u = q.front();
		q.pop();
		vector<Node *> v = u->neighbours;
		int n = v.size();
		for (int i = 0; i < n; i++)
		{
			// Check if this node has already been created
			if (m[v[i]] == NULL)
			{
				// If not then create a new Node and
				// put into the HashMap
				node = new Node();
				node->val = v[i]->val;
				m[v[i]] = node;
				q.push(v[i]);
			}

			// add these neighbours to the cloned graph node
			m[u]->neighbours.push_back(m[v[i]]);
		}
	}

	// Return the address of cloned src Node
	return m[src];
}

// Build the desired graph
Node *buildGraph()
{
	/*
		Note : All the edges are Undirected
		Given Graph:
		1--2
		| |
		4--3
	*/
	Node *node1 = new Node();
	node1->val = 1;
	Node *node2 = new Node();
	node2->val = 2;
	Node *node3 = new Node();
	node3->val = 3;
	Node *node4 = new Node();
	node4->val = 4;
	vector<Node *> v;
	v.push_back(node2);
	v.push_back(node4);
	node1->neighbours = v;
	v.clear();
	v.push_back(node1);
	v.push_back(node3);
	node2->neighbours = v;
	v.clear();
	v.push_back(node2);
	v.push_back(node4);
	node3->neighbours = v;
	v.clear();
	v.push_back(node3);
	v.push_back(node1);
	node4->neighbours = v;
	return node1;
}

// A simple bfs traversal of a graph to
// check for proper cloning of the graph
void bfs(Node *src)
{
	map<Node*, bool> visit;
	queue<Node*> q;
	q.push(src);
	visit[src] = true;
	while (!q.empty())
	{
		Node *u = q.front();
		cout << "Value of Node " << u->val << "\n";
		cout << "Address of Node " <<u << "\n";
		q.pop();
		vector<Node *> v = u->neighbours;
		int n = v.size();
		for (int i = 0; i < n; i++)
		{
			if (!visit[v[i]])
			{
				visit[v[i]] = true;
				q.push(v[i]);
			}
		}
	}
	cout << endl;
}

// Driver program to test above function
int main()
{
	Node *src = buildGraph();
	cout << "BFS Traversal before cloning\n";
	bfs(src);
	Node *newsrc = cloneGraph(src);
	cout << "BFS Traversal after cloning\n";
	bfs(newsrc);
	return 0;
}
