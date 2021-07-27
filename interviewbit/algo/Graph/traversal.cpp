// bfs
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
        l[y].push_back(x);
    }
    void bfs(T src){
        map<T, bool>visited;
        queue<T>q;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto nbr: l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }

        }
        
    }
    void dfs_helper(T src, map<T, bool>&visited){
        cout<<src<<" ";
        visited[src] = true;

        for(auto nbr: l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr, visited);
            }
        }


    }
    void dfs(T src){
        map<T, bool>visited;
        for(auto p: l){
            T node = p.first;
            visited[node] = false;
        }

        dfs_helper(src, visited);
    }
};
int main()
{
    ReadCP();
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0,3);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.bfs(0);
    cout<<endl;
    g.dfs(0);

    return 0;
}