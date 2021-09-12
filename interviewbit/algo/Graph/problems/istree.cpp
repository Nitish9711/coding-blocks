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
    bool is_tree()
    {
        bool *visited = new bool[V];
        int *parent = new int[V];

        queue<int>q;
        for(int i=0;i<V;i++){
            visited[i] = false;
            parent[i] =i;
        }
        int src = 0;
        q.push(src);
        visited[src]   = true;
        
        while (!q.empty())
        {
           int node = q.front();
           q.pop();

           for(int nbr: l[node]){
               if(visited[nbr] == true and parent[node]!= nbr){
                   return false;
               }
               else if(!visited[nbr]){
                   visited[nbr] = true;
                   parent[nbr] = node;
                   q.push(nbr);
                    }
           }
        }
        
        return true;
    }
};
int main()
{
    ReadCP();

    Graph<int> g(6);

    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    // g.addEdge(1, 4);
    // g.addEdge(4, 5);
    // g.addEdge(3, 5);

    // g.top_sort();
    if(g.is_tree()){
        cout<<" tree"<<endl;
    }
    else{
        cout<<"not tree"<<endl;
    }
    return 0;
}