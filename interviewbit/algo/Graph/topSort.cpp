#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define null NULL

void ReadCP()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
template <typename T>
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }

    void top_sort_bfs()
    {
        int *inDegree = new int[V];
        for (int i = 0; i < V; i++)
            inDegree[i] = 0;

        for (int i = 0; i < V; i++)
        {
            for (auto y : l[i])
                inDegree[y]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ->";
            for (auto nbr : l[node])
            {
                inDegree[nbr]--;
                if (inDegree[nbr] == 0)
                    q.push(nbr);
            }
        }
    }

    void dfs_helper(int src, bool visited[], list<int>&order){
        visited[src] = true;
        for(auto nbr: l[src]){
            if(!visited[nbr])
                dfs_helper(nbr, visited, order);
        }
        order.push_front(src);
    }
    void top_sort_dfs(){
        bool * visited = new bool[V];
        list<int>order;
        for (int i = 0; i < V; i++)
            visited[i] = 0;


        for(int i=0;i<V;i++){
            if(!visited[i])
                dfs_helper(i, visited, order);
        }

        for(auto node: order){
            cout<<node<<" ->";
        }

    }


};
int main()
{
    ReadCP();

    Graph<int> g(6);

    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(1, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 5);

    g.top_sort_bfs();
    cout<<endl;
    g.top_sort_dfs();
    return 0;
}