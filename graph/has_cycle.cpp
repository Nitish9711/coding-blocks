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

    bool cycle_helper(int node, bool *visited, bool *stack){
        visited[node] = true;
        stack[node]= true;

        for(int nbr: l[node]){
            if(stack[nbr] == true){
                return true;
            }
            if(visited[nbr] == false){
                bool got_Cycle = cycle_helper(nbr, visited, stack);
                if(got_Cycle == true){
                    return true;
                }
            }
        }
        stack[node] = false;
        return false;

    }
    bool has_cycle()
    {
        bool *visited = new bool[V];
        bool *stack = new bool[V];
        for(int i=0;i<V;i++){
            visited[i] = stack[i] = false;
        }
        return cycle_helper(0, visited, stack);
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
    if(g.has_cycle()){
        cout<<"has cycle"<<endl;
    }
    else{
        cout<<"not has cycle"<<endl;
    }
    return 0;
}