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
template<typename T>
class Graph{
    map<T, list<T>>l;
    public:
    void addEdge(T x, T y ){
        l[x].push_back(y);
        // l[y].push_back(x);
    }

    void dfs_helper(T src, map<T, bool>&visited, list<T>&ordering){
        // cout<<src<<" ";
        visited[src] = true;

        for(T nbr: l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr, visited, ordering);

            }
        }
        ordering.push_front(src);
        return;
    }
    void dfs(){
        map<T, bool> visited;
        list<T> ordering;
        for(auto p : l){
            T node = p.first;
            visited[node] = false;
        }

            int cnt = 0;
        for(auto p: l){
            T src = p.first;
            if(!visited[src]){
                dfs_helper(src, visited, ordering);
            }
            // cout<<endl;
        }

        // dfs_helper(src, visited);

        for(auto node: ordering){
            cout<<node<<endl;
        }
    }

};
int main()
{
    ReadCP();
   

    Graph<int> g;
   
    g.addEdge(5, 0);
    g.addEdge(5, 2);
    g.addEdge(4,0);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 1);
    // g.addEdge(6, 5);
    // g.addEdge(7, 6);

    // g.addEdge(8, 9);

    g.dfs();
   


    return 0;
}