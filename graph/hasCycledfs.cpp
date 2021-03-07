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

    void addEdge(int x, int y, bool directed = true)
    {
        l[x].push_back(y);
        if(!directed){
            l[y].push_back(x);
        }
    }

    bool cycle_helper(int node, bool *visited, int parent){
        
        visited[node] = true;
        for(auto nbr: l[node]){
            if(!visited[nbr]){
                bool cycle_got = cycle_helper(nbr, visited, node);
                if(cycle_got)
                    return true;
            }
            else if(nbr!= parent){
                return true;
            }
        }
        return false;
    }
    bool has_cycle()
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i] = false;
        }
         return cycle_helper(0, visited, -1);
       
    }
};
int main()
{
    ReadCP();

    Graph<int> g(6);

    g.addEdge(0, 1);
    // g.addEdge(3, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    // g.addEdge(4, 0);

    // g.addEdge(1, 4);
    // g.addEdge(4, 5);
    // g.addEdge(3, 5);

    // g.top_sort();
    if(g.has_cycle()){
        cout<<"has cycle"<<endl;
    }
    else{
        cout<<"not has cycle"<<endl;
    }
    return 0;
}