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

    void dfs_helper(T src, map<T, bool>&visited){
        cout<<src<<" ";
        visited[src] = true;

        for(T nbr: l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr, visited);
            }
        }
    }
    void dfs(T src){
        map<T, bool> visited;
        for(auto p : l){
            T node = p.first;
            visited[node] = false;
        }

        dfs_helper(src, visited);
    }

};
int main()
{
    ReadCP();
    // int board[50] = {0};
    // board[5] = 2;
    // board[2] = 13;
    // board[9] = 18;
    // board[18] = 11;
    // board[17] = -13;
    // board[20] = -14;
    // board[24] = -8;
    // board[25] = 10;
    // board[32] = -2;
    // board[34] = -22;

    Graph<int> g;
   
    g.addEdge(0, 1);
    g.addEdge(0,3);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.dfs(0);
   


    return 0;
}