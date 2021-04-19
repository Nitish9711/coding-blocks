#include<iostream>
#include<list>
#include<fstream>
#include<set>
#include<queue>
using namespace std;

class graph {
public:
	int V;
	list<int> *adjList;
	list<int> *realList;

	graph(int V) {
		this->V = V;
		adjList = new list<int>[V];
		realList = new list<int>[V];
	}

	void addEdge(int u, int v) {
		adjList[u].push_back(v);
	}

	void findMasterVerticesAndThenPushEdges() {
		set<int> s;
		for (int i = 0; i < V; i++) {
			s.insert(i);
		}

		while (s.empty() == false) {

			bool visited[V];
			for (int i = 0; i < V; i++) {
				visited[i] = false;
			}

			set<int>::iterator it = s.begin();

			queue<int> q;
			q.push(*it);
			while (q.empty() == false) {
				int x = q.front();
				q.pop();
				visited[x] = true;
				s.erase(x);
				int size = adjList[x].size();
				for (int i = 0; i < size; i++) {
					int k = adjList[x].front();
					adjList[x].pop_front();
					if (visited[k] == false) {
						q.push(k);
						realList[x].push_back(k);
					}
				}
			}
		}
	}

	int beautiful() {
		int child[V];
		for (int i = 0; i < V; i++) child[i] = 0;

		int cnt = 0;

		for (int i = 0; i < V; i++) child[i] = realList[i].size();
		//int arr[100000] = {0};
		for (int i = 0; i < V; i++) {
			int size = realList[i].size();
			for (int k = 0; k < size; k++) {
				//arr[realList[i].front()] = 1;
				if (child[realList[i].front()] > child[i] && child[i] != 0) {
					cnt++;
				}
				realList[i].pop_front();
			}
		}

		return cnt;
	}
};

int main() {
	int n;
	cin >> n;
	graph g(n);
	int m;
	cin >> m;
	int u;
	int v;
	while (m--) {
		cin >> u >> v;
		u--;
		v--;
		g.addEdge(u, v);
		g.addEdge(v, u);
	}

	g.findMasterVerticesAndThenPushEdges();
	cout << g.beautiful();

	return 0;
}